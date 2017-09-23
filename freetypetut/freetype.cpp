#include "ft2build.h"
#include FT_FREETYPE_H
#include <iostream>

int main()
{
    FT_Library ft;
    FT_Face fontface;

    if (FT_Init_FreeType(&ft))
    {
        fprintf(stderr, "Could not init freetype library\n");
        return (1);
    }
    if (FT_New_Face(ft, "Christmas\ in\ finland.ttf"))
    return (0);
}