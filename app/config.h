#ifndef _CONFIG_H__
#define _CONFIG_H__


struct config
{
	char *lua_script;
	unsigned short sleep_time;

	short enable_gpio;
};

extern struct config *config_init(const char *config_file);
extern void config_free(struct config* conf);

#endif
