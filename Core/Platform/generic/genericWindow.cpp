#include "genericWindow.h"

#include "GLFW/glfw3.h"
#ifdef  PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#else   // Assume we are on x11
#define GLFW_EXPOSE_NATIVE_X11 
#endif

#include "GLFW/glfw3native.h"

namespace octo
{
    static u8 s_WindowCount = 0;    /* Only an u8 because if you manage to create more than 256 windows you got other problems */

    GenericWindow::GenericWindow(const WindowDesc& desc)
    {
        if(s_WindowCount == 0)
        {
            glfwInit();
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        m_WindowHandle = glfwCreateWindow(desc.Width, desc.Height, desc.Title.c_str(), nullptr, nullptr);
        s_WindowCount++;
        //TODO: Log here
    }

    GenericWindow::~GenericWindow()
    {
        glfwDestroyWindow((GLFWwindow*)m_WindowHandle);
        s_WindowCount--;

        if(s_WindowCount == 0)
        {
            glfwTerminate();
        }
    }

    void GenericWindow::Update()
    {
        glfwPollEvents();
    }

    void* GenericWindow::GetNativeDisplay()
    {
        #ifdef PLATFORM_LINUX
        return (void*)glfwGetX11Display();
        #else
        return nullptr;
        #endif
    }

    void* GenericWindow::GetNativeWindow()
    {
        #ifdef PLATFORM_LINUX
        return (void*)glfwGetX11Window((GLFWwindow*)m_WindowHandle);
        #else
        return nullptr;
        #endif
    }

} // namespace name
