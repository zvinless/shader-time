#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <shader.hpp>
#include <mesh.hpp>
#include <texture.hpp>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
using namespace std;

const int kWidth = 680;
const int kHeight = 480;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window(
        glfwCreateWindow(kWidth, kHeight, "สวัสดีชาวโลก", nullptr, nullptr),
        glfwDestroyWindow
    );
    glfwMakeContextCurrent(window.get());

    gl3wInit();
    cout << "OpenGL Version " << glGetString(GL_VERSION) << endl;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    stbi_set_flip_vertically_on_load(true);

    auto shader = make_shared<Shader>();
    shader->vert("assets/shaders/vert.vert");
    shader->frag("assets/shaders/frag.frag");
    shader->link();

    auto texture = make_shared<Texture>("assets/textures/e.png");

    vector<Vertex> vertices {
        { { -1, -1 }, { 0, 0 } },
        { { -1, +1 }, { 0, 1 } },
        { { +1, +1 }, { 1, 1 } },
        { { +1, -1 }, { 1, 0 } }
    };

    vector<glm::uvec3> indices {
        { 0, 1, 2 },
        { 0, 2, 3 }
    };

    Mesh mesh(move(vertices), move(indices));
    mesh.setShader(shader);

    while (!glfwWindowShouldClose(window.get()))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mesh.draw();

        glfwPollEvents();
        glfwSwapBuffers(window.get());
    }

    return 0;
}
