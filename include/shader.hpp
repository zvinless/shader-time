#pragma once
#include <GL/gl3w.h>
#include <string>
#include <iostream>

class Shader
{
public:
    Shader() { program = glCreateProgram(); }
    ~Shader() { glDeleteProgram(program); }
    void vert(const std::string& source);
    void frag(const std::string& source);
    void link();
    void use();
    GLuint getProgram() const { return program; }
private:
    GLuint program;
    GLint i;
    void attach(GLenum shaderType, const std::string& path);
};
