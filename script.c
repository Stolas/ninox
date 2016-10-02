#include <stdlib.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "script.h"
#include "mycurses.h"

/* Script Implements */
static int l_print(lua_State *L)
{
	int color = lua_tonumber(L, 1);
	int x = lua_tonumber(L, 2);
	int y = lua_tonumber(L, 3);
	char *str = lua_tostring(L, 4);

	window_print(color, x, y, str);
	return 0;
}

/* Core */
extern struct script *script_init()
{
	struct script *s;

	s = malloc(sizeof(struct script));
	if(s == NULL) {
		return NULL;
	}

	s->L = luaL_newstate();
	luaL_openlibs(s->L);
	lua_register(s->L, "nprint", &l_print);
	return s;
}

void script_run(struct script *s, char *filename)
{
	int status;
	if(s == NULL) {
		return;
	}

	status = luaL_loadfile(s->L, filename);
	if(status) {
		/* TODO: Cleanup.. */
		fprintf(stderr, "Couldn't load file: %s\n", lua_tostring(s->L, -1));
		exit(1);
	}


	status = lua_pcall(s->L, 0, LUA_MULTRET, 0);
	if(status) {
		/* TODO: Cleanup.. */
		fprintf(stderr, "Failed to run script: %s\n", lua_tostring(s->L, -1));
		exit(1);
	}
}

void script_free(struct script *s)
{
	lua_close(s->L);
	free(s);
}

