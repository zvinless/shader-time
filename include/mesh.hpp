#pragma once
#include <GL/gl3w.h>
#include <glm/glm.hpp>
#include <vertex.hpp>
#include <shader.hpp>
#include <vector>
#include <memory>

class Mesh
{
public:
    Mesh(std::vector<Vertex>&& vertices, std::vector<glm::uvec3>&& indices);
    ~Mesh()
    {
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
        glDeleteVertexArrays(1, &vao);
    }
    void setShader(std::shared_ptr<Shader> shader);
    void draw();
private:
    std::vector<Vertex> vertices;
    std::vector<glm::uvec3> indices;
    std::shared_ptr<Shader> shader;
    GLuint vao, vbo, ebo;
};
