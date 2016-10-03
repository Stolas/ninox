#include <stdlib.h>
#include <unistd.h>
#include "mycurses.h"
#include "script.h"
#include "config.h"
#include "gpio.h"

int main(int argc, char **argv)
{
	struct script *s;
	struct config *c;
	WINDOW *window;

	c = config_init(NULL);
	window = window_init();
	s = script_init();

	if(gpio_init() != EXIT_SUCCESS) {
		window_clear(window);
		window_print(1, 0, 0, "ERROR");
		return EXIT_FAILURE;
	}

	for(;;) {
		script_run(s, c->lua_script);
		sleep(c->sleep_time);
		window_clear(window);
	}

	window_free(window);
	script_free(s);
	return EXIT_SUCCESS;
}
