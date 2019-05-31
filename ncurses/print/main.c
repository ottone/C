#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

int main(){

	srand(time(NULL));
	unsigned int a;
	int row , col;

	initscr();
	while(1){
		
		getmaxyx(stdscr, row, col);
		a = time(0) + 1; 
		while(time(0) < a);
		clear();
		mvprintw(1 + (rand() % row),1 + (rand() % col), "Hello Word!!!");
		refresh();

	}
	
	endwin();
	return 0;
}
