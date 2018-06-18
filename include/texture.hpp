#pragma once
#include <GL/gl3w.h>
#include <stb_image.h>
#include <string>
#include <memory>

class Texture
{
public:
    Texture(std::string_view path);
    ~Texture() { glDeleteTextures(1, &tex); }
    const int& x = _x;
    const int& y = _y;
    const int& n = _n;
private:
    GLuint tex;
    int _x, _y, _n;
};
