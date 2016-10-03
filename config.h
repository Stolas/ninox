#ifndef _CONFIG_H__
#define _CONFIG_H__

typedef int bool;

#define FALSE (0)
#define TRUE (!FALSE)


struct config
{
	const char *lua_script;
	unsigned short sleep_time;

	bool enable_gpio;
};

extern struct config *config_init(const char *config_file);
extern void config_free(struct config* conf);

#endif
