#include "Base.h"
#include "lua_FontStyle.h"

namespace gameplay
{

static const char* enumStringEmpty = "";

static const char* luaEnumString_FontStyle_PLAIN = "PLAIN";
static const char* luaEnumString_FontStyle_BOLD = "BOLD";
static const char* luaEnumString_FontStyle_ITALIC = "ITALIC";
static const char* luaEnumString_FontStyle_BOLD_ITALIC = "BOLD_ITALIC";
static const char* luaEnumString_FontStyle_TEXTURED = "TEXTURED";

Font::Style lua_enumFromString_FontStyle(const char* s)
{
    if (strcmp(s, luaEnumString_FontStyle_PLAIN) == 0)
        return Font::PLAIN;
    if (strcmp(s, luaEnumString_FontStyle_BOLD) == 0)
        return Font::BOLD;
    if (strcmp(s, luaEnumString_FontStyle_ITALIC) == 0)
        return Font::ITALIC;
    if (strcmp(s, luaEnumString_FontStyle_BOLD_ITALIC) == 0)
        return Font::BOLD_ITALIC;
    if (strcmp(s, luaEnumString_FontStyle_TEXTURED) == 0)
        return Font::TEXTURED;
    GP_ERROR("Invalid enumeration value '%s' for enumeration Font::Style.", s);
    return Font::PLAIN;
}

const char* lua_stringFromEnum_FontStyle(Font::Style e)
{
    if (e == Font::PLAIN)
        return luaEnumString_FontStyle_PLAIN;
    if (e == Font::BOLD)
        return luaEnumString_FontStyle_BOLD;
    if (e == Font::ITALIC)
        return luaEnumString_FontStyle_ITALIC;
    if (e == Font::BOLD_ITALIC)
        return luaEnumString_FontStyle_BOLD_ITALIC;
    if (e == Font::TEXTURED)
        return luaEnumString_FontStyle_TEXTURED;
    GP_ERROR("Invalid enumeration value '%d' for enumeration Font::Style.", e);
    return enumStringEmpty;
}

}

