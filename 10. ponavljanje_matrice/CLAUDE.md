# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This directory (`ponavljanje_matrice`) is part of an educational C++ workshop repository for a Bosnian-language programming school (`iobih_skola_26_ada`). It covers matrix review topics:
- `1. simulacija pozara/` — Fire simulation exercise
- `2. osnove matrica/` — Matrix basics (currently being developed)
- `3. primjeri zadataka/` — Example tasks

## Building and Running C++ Files

Each `.cpp` file is compiled individually using g++. No build system (Makefile/CMake) is used.

**Compile a single file:**
```bash
g++ -fdiagnostics-color=always -g -o <filename>.out <filename>.cpp
```

**Run the compiled binary:**
```bash
./<filename>.out
```

**VSCode:** The default build task ("C/C++: g++ build active file") compiles the active file automatically. Press `F5` to build and debug with GDB.

## Repository Structure

This directory lives within the larger repo at `../` (root: `iobih_skola_26_ada`):

- `operatori_logika/` — Arithmetic, logical/relational operators, if/switch, Unix time examples
- `ugnijezdjene_petlje/` — Nested loops, patterns, infinite loop examples, exercises
- `ponavljanje_matrice/` — Matrix review (this directory)
- `sazeci_predavanja/` — Lecture summaries in Markdown (Bosnian)
- `transkripti_predavanja/` — Lecture transcripts
- `main.py` — Lecture schedule timing calculator

## Code Style

- Bosnian variable names and comments throughout
- Prefer `using namespace std;` over explicit `std::cout`/`std::cin`
- No external C++ library dependencies (standard library only)
- Each `.cpp` file is self-contained and independently compilable

## Python

The root directory has a `.venv/` (Python 3.11). See root `CLAUDE.md` for Python library install instructions.
