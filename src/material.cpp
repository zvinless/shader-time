#include <material.hpp>
using namespace std;

Material::Material(shared_ptr<Shader> shader)
    : shader(shader)
{
}

void Material::setTexture(const string& name, const Texture& texture)
{
    auto location = glGetUniformLocation(shader->getProgram(), name.data());
    shader->use();
    glUniform1i(location, texture.unit);
}

float Material::getFloat(const string& name)
{
    auto location = glGetUniformLocation(shader->getProgram(), name.data());
    GLfloat f;
    glGetUniformfv(shader->getProgram(), location, &f);
    return f;
}

void Material::setFloat(const string& name, const float& f)
{
    auto location = glGetUniformLocation(shader->getProgram(), name.data());
    shader->use();
    glUniform1f(location, f);
}
