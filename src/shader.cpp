#include <shader.hpp>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void Shader::vert(const string& path)
{
    attach(GL_VERTEX_SHADER, path.data());
}

void Shader::frag(const string& path)
{
    attach(GL_FRAGMENT_SHADER, path.data());
}

void Shader::link()
{
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &i);
    if (i == GL_FALSE)
    {
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &i);
        vector<char> buffer(i);
        glGetProgramInfoLog(program, i, nullptr, buffer.data());
        cerr << "LINK PROBLEM" << endl << buffer.data();
    }
}

void Shader::attach(GLenum shaderType, const string& path)
{
    auto file = ifstream(path.data());
    auto source = string(istreambuf_iterator<char>(file), {});
    auto shader = glCreateShader(shaderType);
    const auto cString = source.c_str();
    glShaderSource(shader, 1, &cString, nullptr);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &i);
    if (i == GL_FALSE)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &i);
        vector<char> buffer(i);
        glGetShaderInfoLog(shader, i, nullptr, buffer.data());
        cerr << path << endl << buffer.data();
        glDeleteShader(shader);
        return;
    }
    glAttachShader(program, shader);
    glDeleteShader(shader);
}

void Shader::use()
{
    glUseProgram(program);
}
