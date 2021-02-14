//
//  MacWindow.cpp
//  HAZEL Xcode
//
//  Created by Roberto Serrano on 13/02/21.
//

#include "MacWindow.h"
#include "log.h"

namespace Hazel {

    static bool s_GLFWInitilized = false;
    
    Window* Window::Create( const WindowProps& props)
    {
        return new MacWindow( props );
    }

    MacWindow::MacWindow( const WindowProps& props)
    {
        Init(props);
    }
    
    MacWindow::~MacWindow()
    {
        Shutdown();
    }

    void MacWindow::Init(const WindowProps& props)
    {
        m_Data.Title  = props.Title;
        m_Data.Width  = props.Width;
        m_Data.Height = props.Height;
        
        HZ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height );
        
        if (!s_GLFWInitilized)
        {
            // TODO terminate on system shutdown
            int sucess = glfwInit();
            HZ_CORE_ERROR("Error initializing GLFW!");
            
            s_GLFWInitilized =  true;
        }
        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr );
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVsync(true);
    }

    void MacWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void MacWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void MacWindow::SetVsync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        
        m_Data.VSync = enabled;
    }

    bool MacWindow::IsVSync() const
    {
        return m_Data.VSync;
    }

}

