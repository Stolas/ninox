#include <unistd.h>
#include "mycurses.h"
#include "script.h"

int main(int argc, char **argv)
{
	struct script *s;
	WINDOW *window;

	s = script_init();
	window = window_init();

	for(;;) {
		script_run(s, "main.lua");
		sleep(3);
	}

	window_free(window);
	script_free(s);
}
