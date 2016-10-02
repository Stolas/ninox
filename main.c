#include <stdlib.h>
#include <unistd.h>
#include "mycurses.h"
#include "script.h"
#include "gpio.h"

int main(int argc, char **argv)
{
	struct script *s;
	WINDOW *window;

	window = window_init();
	s = script_init();

	if(gpio_init() != EXIT_SUCCESS) {
		window_clear(window);
		window_print(1, 0, 0, "ERROR");
		return EXIT_FAILURE;
	}

	for(;;) {
		script_run(s, "main.lua");
		sleep(3);
	}

	window_free(window);
	script_free(s);
	return EXIT_SUCCESS;
}
