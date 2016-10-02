#include <stdlib.h>
#include <stdio.h>
#include "mycurses.h"


WINDOW *window_init()
{
	WINDOW *mainwin;
	mainwin = initscr();
	if(mainwin == NULL) {
		return NULL;
	}
	start_color(); /*  Initialize colours  */

	if(has_colors() && COLOR_PAIRS >= 13) {
		init_pair(1,  COLOR_RED,     COLOR_BLACK);
		init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
		init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
		init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
		init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
		init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
		init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
		init_pair(8,  COLOR_WHITE,   COLOR_RED);
		init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
		init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
		init_pair(11, COLOR_WHITE,   COLOR_BLUE);
		init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
		init_pair(13, COLOR_BLACK,   COLOR_CYAN);
	}
	return mainwin;
}

void window_print(int color, int x, int y, char *str) {
	color_set(color, NULL);
	mvaddstr(y, x, str);
	refresh();
}

void window_clear(WINDOW *win)
{
	wclear(win);
}

void window_free(WINDOW *win)
{
	delwin(win);
	endwin();
	refresh();
}