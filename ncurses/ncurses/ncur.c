// File ncur.c

#include "ncursesw/curses.h"

void main()
{
     initscr();
     addstr("Hello World con Ncurses!\n\n");
     addstr("Premere un tasto, per uscire da Ncurses...");
     getch();
     refresh();
     endwin();
}
