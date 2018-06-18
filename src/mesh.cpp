#include <glm/glm.hpp>
#include <mesh.hpp>
#include <shader.hpp>
#include <iostream>
using namespace std;

Mesh::Mesh(vector<Vertex>&& vertices, vector<glm::uvec3>&& indices)
    : vertices(vertices)
    , indices(indices)
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
        GL_ARRAY_BUFFER,
        vertices.size() * sizeof(Vertex),
        vertices.data(),
        GL_STATIC_DRAW
    );

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        indices.size() * sizeof(glm::uvec3),
        indices.data(),
        GL_STATIC_DRAW
    );

    glBindVertexArray(0);
}

void Mesh::setShader(shared_ptr<Shader> shader)
{
    this->shader = shader;

    glBindVertexArray(vao);
    auto program = shader->getProgram();
    auto position = glGetAttribLocation(program, "position");
    auto uv = glGetAttribLocation(program, "uv");
    glVertexAttribPointer(
        position,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        (GLvoid*) offsetof(Vertex, position)
    );
    glVertexAttribPointer(
        uv,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        (GLvoid*) offsetof(Vertex, uv)
    );
    glEnableVertexAttribArray(position);
    glEnableVertexAttribArray(uv);
    glBindVertexArray(0);
}

void Mesh::draw()
{
    shader->use();
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size() * 3, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
    glUseProgram(0);
}
