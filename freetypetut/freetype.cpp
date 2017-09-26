#include "ft2build.h"
#include FT_FREETYPE_H
#include <iostream>

int main()
{
    // GLuint tex;
    FT_Library ft;
    FT_Face fontface;
    FT_GlyphSlot gslot = fontface->glyph;

    if (FT_Init_FreeType(&ft))
    {
        fprintf(stderr, "Could not init freetype library\n");
        return (1);
    }
    if (FT_New_Face(ft, "finland.ttf", 0, &fontface))
    {
        fprintf(stderr, "Could not open font\n");
        return (1);
    }
    FT_Set_Pixel_Sizes(fontface, 0, 48);
    FT_Load_Char(fontface, 'R', FT_LOAD_RENDER);
    // glEnable(GL_BLEND);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // glActiveTexture(GL_TEXTURE0);
    // glGenTextures(1, &tex);
    // glBindTexture(GL_TEXTURE_2D, tex);
    // glUniform1i(uniform_tex, 0);
    return (0);
}