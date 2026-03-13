#include <iostream>

using namespace std;

int main() {
    









    //MARK: aplikacija
    """
    Primjer u aplikaciji
    """
    while (true) {
        Event e = get_next_event();

        if (e.type == CLICK)
            handle_click(e);

        if (e.type == KEY_PRESS)
            handle_key(e);
    }




























    // MARK: igrica
    """
    Primjer u igrici
    """

    while (game_running) {
        process_input();
        update_game_state();
        render_frame();
    }























    


    // MARK: input
    while (true) {
        int n;
        cin >> n;

        if (n == -1) {
            break;
        }

        // Ovdje radimo nesto


    }















    





    return 0;
}

