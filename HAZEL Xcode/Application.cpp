#include <sstream>

#include "Application.h"
#include "log.h"
#include "spdlog/spdlog.h"
#include "ApplicationEvent.h"
#include "MouseEvent.h"
#include "GLFW/glfw3.h"

namespace Hazel {

#define BIND_EVENT_FN(x)std::bind(&x, this, std::placeholders::_1)
    Application::Application()
    {
        m_Window = std::unique_ptr<Hazel::Window>(Window::Create());
        m_Window->SetEventCallback( BIND_EVENT_FN( Application::OnEvent ) );
    };

    Application::~Application()
    {
    };

    void Application::OnEvent( Event& e)
    {
        HZ_CORE_INFO( "{0}", e );
    };

    void Application::Run()
    {
        while (m_Running){
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        };
    };
}
