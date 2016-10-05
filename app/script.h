#ifndef _SCRIPT_H__
#define _SCRIPT_H__

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

struct script {
	lua_State *L;
};

extern struct script *script_init();
extern void script_run(struct script *s, char *filename);
extern void script_free(struct script *s);

#endif
