#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "mycurses.h"
#include "script.h"
#include "config.h"
#include "gpio.h"

void *draw_function(void *arg)
{
	WINDOW *window;
	struct config *c;

	c = (struct config*)arg;

	window = window_init();
	for(;;) {
		sleep(c->sleep_time);
		window_clear(window);
	}
	window_free(window);
	return NULL;
}

void *script_function(void *arg)
{
	struct script *s;
	struct config *c;

	c = (struct config*)arg;

	s = script_init();
	for(;;) {
		script_run(s, c->lua_script);
		sleep(c->sleep_time);
	}
	script_free(s);

	return 0;
}

int main(int argc, char **argv)
{
	struct config *c;
	pthread_t draw_thread;
	pthread_t script_thread;

	c = config_init(NULL);

	// if(gpio_init() != EXIT_SUCCESS) {
	// 	window_clear(window);
	// 	window_print(1, 0, 0, "ERROR");
	// 	return EXIT_FAILURE;
	// }

	pthread_create(&draw_thread, NULL, draw_function, (void*)c);
	pthread_create(&script_thread, NULL, script_function, (void*)c);

	pthread_join(draw_thread, NULL);
	pthread_join(script_thread, NULL);

	return EXIT_SUCCESS;
}
