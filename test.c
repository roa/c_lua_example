#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

/*
 * the function which can be used in lua
 * * * * * * * * * * * * * * * * * * * */
static int l_test ( lua_State *L )
{
    double d = luaL_Checknumber( L, 1 );
    lua_pushnumber( L, d );
    return 1;
}

/*
 * put the function l_test as test in the
 * test table
 * * * * * * * * * * * * * * * * * * * */
static const struct luaL_Reg test [] = {
    { "test", l_test },
    { NULL, NULL }
};

/*
 * makes the test table avaiable as test
 * in lua
 * * * * * * * * * * * * * * * * * * * */
int luaopen_test ( lua_State *L )
{
    luaL_register( L, "test", test );
    return 1;
}
