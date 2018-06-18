#pragma once
#include <GL/gl3w.h>
#include <string>
#include <iostream>

class Shader
{
public:
    Shader() { program = glCreateProgram(); }
    ~Shader() { glDeleteProgram(program); }
    void vert(std::string_view source);
    void frag(std::string_view source);
    void link();
    void use();
    GLuint getProgram() const { return program; }
private:
    GLuint program;
    GLint i;
    void attach(GLenum shaderType, std::string_view path);
};
