#ifndef _CURSES_H__
#define _CURSES_H__

#include <curses.h>

#define COLOR_ERROR (1)
#define COLOR_OK (2)
#define COLOR_WARNING (3)
#define COLOR_TEXT (4)

extern WINDOW *window_init();
extern void window_print_raw(int color, int y, int x, char *str);
extern void window_print(int color, int y, int x, char *str);
extern void window_clear(WINDOW *win);
extern void window_error(char *str);
extern void window_free(WINDOW *win);

#endif
