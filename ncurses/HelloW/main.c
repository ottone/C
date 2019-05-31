#include <stdio.h>
#include <ncurses.h>

int main(){
	
	initscr(); 			// Start curses mode
	printw("Hello word !!!");	// Print Hello Word
	refresh();			// Print it on to the real screen
	getch();			// Wait for user input
	endwin();			// End curses mode


	printf("Hello word !!!");

	return 0;
}
