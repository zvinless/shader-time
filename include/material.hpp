#pragma once
#include <texture.hpp>
#include <shader.hpp>
#include <iostream>
#include <memory>

class Material
{
public:
    Material(std::shared_ptr<Shader> shader);
    void setTexture(const std::string& name, const Texture& texture);
    float getFloat(const std::string& name);
    void setFloat(const std::string& name, const float& f);
    void drawTime() { shader->use(); }
private:
    std::shared_ptr<Shader> shader;
};
