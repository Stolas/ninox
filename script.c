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
	int y = lua_tonumber(L, 2);
	int x = lua_tonumber(L, 3);
	char *str = (char*)lua_tostring(L, 4);

	window_print(color, y, x, str);
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
		window_error("Failed to load file");
	}


	status = lua_pcall(s->L, 0, LUA_MULTRET, 0);
	if(status) {
		// fprintf(stderr, "Failed to run script: %s\n", lua_tostring(s->L, -1));
		window_error("Failed to run script.");
	}
}

void script_free(struct script *s)
{
	lua_close(s->L);
	free(s);
}

