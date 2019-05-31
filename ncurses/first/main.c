#include <ncurses.h>

int main(void){
	
	initscr();
	printw("Ciao, sono il tuo primo programma con ncurses, premi un tasto per uscire");

	refresh();
	getch();
	endwin();
	return 0;
}
