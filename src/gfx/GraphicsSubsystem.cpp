#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "gfx/SpriteBatch.hpp"
#include "gfx/WindowSubsystem.hpp"
#include "util/types.hpp"
#include "gfx/GraphicsSubsystem.hpp"

u8 GraphicsSubsystem::init(WindowSubsystem* wSubSys) {
    const char* defaultVertexShader =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main() {\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    
    const char* defaultFragShader = 
        "#version 330 core\n"
        "out vec4 fragColor;\n"
        "void main() {\n"
        "   fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";
    this->win = wSubSys->win;
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &defaultVertexShader, nullptr);
    glCompileShader(vertexShader);
    int success;
    char log[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, log);
        std::cout << "Vertex shader compilation failed: " << log << std::endl;
        return 1;
    }

    u32 fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &defaultFragShader, nullptr);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragShader, 512, nullptr, log);
        std::cout << "Fragment shader compilation failed: " << log << std::endl;
        return 1;
    }

    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, vertexShader);
    glAttachShader(this->shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    return 0;
}

void GraphicsSubsystem::prepareFrame() {
    i32 width, height;
    glfwGetFramebufferSize(this->win, &width, &height);
    glViewport(0, 0, width, height);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(this->shaderProgram);
}

void GraphicsSubsystem::finishFrame(SpriteBatch* sb) {
    auto drawData = sb->getDrawData();
    for (auto& drawable : drawData) {
        drawable->draw();
    }

    glfwSwapBuffers(this->win);
    glfwPollEvents();
}

SpriteBatch GraphicsSubsystem::spriteBatch() {
    i32 width, height;
    glfwGetFramebufferSize(this->win, &width, &height);
    SpriteBatch batch;
    batch.winx = width;
    batch.winy = height;
    return batch;
}

Sprite GraphicsSubsystem::loadSprite(const char* name) {
    Sprite spr;
    spr.load();
    return spr;
}

