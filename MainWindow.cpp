#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

#include "MainWindow.h"
#include "Input.h"
#include "RenderLoop.h"

// 窗口尺寸定义
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

int main()
{
    InitGLFW();

    GLFWwindow* window = CreateWindow();

    // 初始化glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 绘制循环
    while (!glfwWindowShouldClose(window))
    {
        ProcessInput(window);

        RenderLoop(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 退出程序
    glfwTerminate();
    return 0;
}


// 初始化GLFW
void InitGLFW() 
{
    glfwInit();

    // 设置OpenGL支持版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // 使用OpenGL核心模式
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


// 创建窗口对象
GLFWwindow* CreateWindow()
{
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "SoftRendererGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);

    // 设置窗口大小变化时的回调
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

// 窗口改变回调
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

