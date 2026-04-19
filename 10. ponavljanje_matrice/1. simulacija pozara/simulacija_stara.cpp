#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

// ── Configuration ─────────────────────────────────────────────────────────
static const int    ROWS         = 20;
static const int    COLS         = 50;
static const double TREE_DENSITY = 0.65;  // fraction of cells that start as trees
static const double SPREAD_PROB  = 0.40;  // probability fire spreads to each tree neighbor

// Initial burning cells (row, col) — 0-indexed
static const std::vector<std::pair<int,int>> INIT_FIRE = {
    {10, 24},
    {10, 25},
    { 9, 25},
};

static const int MAX_STEPS = 80;   // hard limit on number of steps
static const int DELAY_MS  = 150;  // milliseconds between steps
// ──────────────────────────────────────────────────────────────────────────

enum Cell { EMPTY, TREE, BURNING, BURNED };

using Grid = std::vector<std::vector<Cell>>;

// ── Grid construction ──────────────────────────────────────────────────────

Grid makeGrid() {
    Grid g(ROWS, std::vector<Cell>(COLS, EMPTY));
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (static_cast<double>(rand()) / RAND_MAX < TREE_DENSITY)
                g[r][c] = TREE;
    for (auto [r, c] : INIT_FIRE)
        g[r][c] = BURNING;
    return g;
}

// ── Simulation step ────────────────────────────────────────────────────────

// Rules:
//   BURNING → BURNED  (fire burns out after one step)
//   TREE adjacent to a BURNING cell → catches fire with probability SPREAD_PROB
//     (each burning neighbor is an independent chance; more neighbors = higher risk)
Grid step(const Grid& g) {
    Grid next = g;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (g[r][c] != BURNING) continue;
            next[r][c] = BURNED;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) continue;
                    if (g[nr][nc] == TREE && static_cast<double>(rand()) / RAND_MAX < SPREAD_PROB)
                        next[nr][nc] = BURNING;
                }
            }
        }
    }
    return next;
}

// ── Plotting ───────────────────────────────────────────────────────────────

void plot(const Grid& g, int step) {
    // Reposition cursor to top-left so each frame overwrites the last
    std::cout << "\033[H";

    std::cout << "=== Wildfire Simulation";
    if (step >= 0) std::cout << " — Step " << step;
    std::cout << " ===\n";

    std::cout << '+' << std::string(COLS, '-') << "+\n";
    for (int r = 0; r < ROWS; r++) {
        std::cout << '|';
        for (int c = 0; c < COLS; c++) {
            switch (g[r][c]) {
                case EMPTY:   std::cout << "\033[2m.\033[0m";      break; // dim
                case TREE:    std::cout << "\033[32mT\033[0m";      break; // green
                case BURNING: std::cout << "\033[91m*\033[0m";      break; // bright red
                case BURNED:  std::cout << "\033[90mx\033[0m";      break; // dark gray
            }
        }
        std::cout << "|\n";
    }
    std::cout << '+' << std::string(COLS, '-') << "+\n";

    int trees = 0, burning = 0, burned = 0;
    for (auto& row : g)
        for (Cell cell : row) {
            if (cell == TREE)    trees++;
            if (cell == BURNING) burning++;
            if (cell == BURNED)  burned++;
        }
    std::cout << "Trees: "   << trees
              << "  \033[91mBurning: " << burning << "\033[0m"
              << "  \033[90mBurned: "  << burned  << "\033[0m"
              << "    \n";
}

// ── Main ───────────────────────────────────────────────────────────────────

bool anyBurning(const Grid& g) {
    for (auto& row : g)
        for (Cell c : row)
            if (c == BURNING) return true;
    return false;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::cout << "\033[2J"; // clear screen once at start

    Grid g = makeGrid();

    for (int t = 0; t <= MAX_STEPS; t++) {
        plot(g, t);
        if (!anyBurning(g)) {
            std::cout << "\nFire extinguished after " << t << " step(s).\n";
            return 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_MS));
        g = step(g);
    }

    plot(g, MAX_STEPS);
    std::cout << "\nMax steps reached. Fire still active.\n";
    return 0;
}
