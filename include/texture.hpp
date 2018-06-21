#pragma once
#include <GL/gl3w.h>
#include <stb_image.h>
#include <string>
#include <memory>

class Texture
{
public:
    const int& x = _x;
    const int& y = _y;
    const int& n = _n;
    const GLuint& tex = _tex;
    const GLuint& unit = _unit;
    Texture(const std::string& path);
    ~Texture() { glDeleteTextures(1, &tex); }
    GLenum getTextureUnit() const { return GL_TEXTURE0 + unit; }
private:
    static int counter;
    GLuint _unit;
    GLuint _tex;
    int _x, _y, _n;
};
