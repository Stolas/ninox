#include <stdlib.h>
#include "config.h"


struct config* config_init(const char *config_file)
{
	struct config* conf;
	conf = malloc(sizeof*conf);
	if(conf == NULL) {
		return NULL;
	}

	conf->lua_script = "main.lua";
	conf->sleep_time = 3;
	conf->enable_gpio = 1;

	if(config_file != NULL) {
		/* TODO: Load Config. */
	}

	return conf;
}

void config_free(struct config* conf)
{
	free(conf);
}
