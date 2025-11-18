//  g++ -o make-menu make-menu.cpp -lncurses -lmenu -lpanel
#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>

// Συνάρτηση που ανανεώνει το παράθυρο του μενού
void refresh_menu_window(MENU *my_menu, WINDOW *my_menu_win) {
    // Προσθήκη πλαισίου και τίτλου
    box(my_menu_win, 0, 0); // σχεδιάζει ένα πλαίσιο γύρω από ένα παράθυρο χρησιμοποιώντας οριζόντιες και κάθετες γραμμές.
    mvwprintw(my_menu_win, 1, 1, "Simple Menu");
    post_menu(my_menu);
    wrefresh(my_menu_win);
}

// Συνάρτηση που επαναφέρει το μενού στην αρχική του κατάσταση
void reset_to_initial_menu(MENU *my_menu, WINDOW *my_menu_win) {
    // Διαγραφή του παραθύρου
    wclear(my_menu_win);
    
    // Επαναφορά του μενού στην αρχική του κατάσταση
    set_menu_mark(my_menu, "*"); // Ορίστε το σημάδι της τρέχουσας επιλογής
    set_menu_format(my_menu, LINES - 3, COLS - 1); // Ορίστε το format του μενού
    
    // Ανανεώνουμε το παράθυρο μενού και το εμφανίζουμε ξανά
    refresh_menu_window(my_menu, my_menu_win);
}

int main() {
    // Ξεκινάμε το ncurses
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Ορίζουμε ένα ζεύγος χρωμάτων
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    // Δημιουργία στοιχείων μενού
    const char *choices[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit",
        NULL
    };

    // Δημιουργία πίνακα με τα στοιχεία του μενού (my_items)
    ITEM **my_items = (ITEM **)calloc(4 + 1, sizeof(ITEM *));
    for (int i = 0; choices[i]; ++i) {
        my_items[i] = new_item(choices[i], NULL);
    }

    // Δημιουργία μενού
    MENU *my_menu = new_menu((ITEM **)my_items);
    
    // Δημιουργία παραθύρου για το μενού
    // Το menu θα έχει full size μέγεθος
    int height, width;
    getmaxyx(stdscr, height, width);

    // Δημιουργία ενός παραθύρου πλήρους μεγέθους
    WINDOW *my_menu_win = newwin(height, width, 0, 0);    
    wbkgd(my_menu_win, COLOR_PAIR(1));
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));

    // Ανανεώνουμε το παράθυρο μενού
    refresh_menu_window(my_menu, my_menu_win);

    // Δηλώνουμε μια σημαία (`flag`) που ελέγχει αν επιλέχθηκε μια επιλογή
    int flag = 0; // Αρχικά `false` (0) σημαίνει ότι το μενού μπορεί να κινηθεί

    // Βρόχος για διαχείριση εισόδου χρήστη και χειρισμό μενού
    int c;
    while ((c = wgetch(my_menu_win)) != 'q') {
        // Ελέγχουμε αν η σημαία είναι `true`
        if (flag == 0) {
            switch (c) {
                case 's': // Μετακίνηση προς τα κάτω
                    menu_driver(my_menu, REQ_DOWN_ITEM);
                    break;
                case 'w': // Μετακίνηση προς τα πάνω
                    menu_driver(my_menu, REQ_UP_ITEM);
                    break;
            }
        }
        ITEM *cur_item;
        switch (c) {
            case 10: // Πλήκτρο Enter
                // Λαμβάνουμε την τρέχουσα επιλογή
                cur_item = current_item(my_menu);
                if (strcmp(item_name(cur_item), "Exit") == 0) {
                    goto end_label;
                } else if (strcmp(item_name(cur_item), "Option 1") == 0) {
                    // Διαγραφή του παραθύρου και εμφάνιση νέου κειμένου
                    wclear(my_menu_win);
                    box(my_menu_win, 0, 0);
                    mvwprintw(my_menu_win, 1, 1, "Option 1 (0: return main menu)");
		                mvwprintw(my_menu_win, 2, 1, "You selected Option 1!");
                    wrefresh(my_menu_win);
                    // Ορίστε τη σημαία σε `true`
                    flag = 1;
                } else if (strcmp(item_name(cur_item), "Option 2") == 0) {
                    // Διαγραφή του παραθύρου και εμφάνιση νέου κειμένου
                    wclear(my_menu_win);
                    box(my_menu_win, 0, 0);
                    mvwprintw(my_menu_win, 1, 1, "Option 2 (0: return main menu)");
            		    mvwprintw(my_menu_win, 2, 1, "You selected Option 2!");
                    wrefresh(my_menu_win);
                    // Ορίστε τη σημαία σε `true`
                    flag = 1;
                } else if (strcmp(item_name(cur_item), "Option 3") == 0) {
                    // Διαγραφή του παραθύρου και εμφάνιση νέου κειμένου
                    wclear(my_menu_win);
                    box(my_menu_win, 0, 0);
                    mvwprintw(my_menu_win, 1, 1, "Option 3 (0: return main menu)");
		                mvwprintw(my_menu_win, 2, 1, "You selected Option 3!");
		                wrefresh(my_menu_win);
                    // Ορίστε τη σημαία σε `true`
                    flag = 1;
                }
                break;
            case '0': // Εάν πατηθεί το πλήκτρο `0`
                // Επαναφέρετε τη σημαία σε `false`
                flag = 0;
                // Καλούμε τη συνάρτηση για επαναφορά του μενού
                reset_to_initial_menu(my_menu, my_menu_win);
                break;
        }
        wrefresh(my_menu_win);
    }

end_label:
    // Καθαρισμός πόρων
    unpost_menu(my_menu);
    free_menu(my_menu);
    for (int i = 0; choices[i]; ++i) {
        free_item(my_items[i]);
    }

    // Τερματίζουμε το ncurses
    endwin();

    return 0;
}
