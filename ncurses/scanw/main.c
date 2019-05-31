#include <ncurses.h>		// ncurses.h includes stdio.h
#include <string.h>

int main(){

	char mesg[] = "Enter a string";		// message to be appeared on the screen
	char str[80];
	int row, col;				// to store the number of rows and the number of columns of the scree

	initscr();				// start the curses mode
	getmaxyx(stdscr, row, col);		// get the number of rows and columns
	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);   // print the message at the centre of the message
	getstr(str);
	mvprintw(LINES - 2, 0, "You Entered: %s - LINES : %d ",str, LINES);
	//getch();
	endwin();

	return 0;

}

