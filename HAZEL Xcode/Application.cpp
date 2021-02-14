#include <sstream>

#include "Application.h"
#include "log.h"
#include "spdlog/spdlog.h"
#include "ApplicationEvent.h"
#include "MouseEvent.h"
#include "GLFW/glfw3.h"

namespace Hazel {

  Application::Application()
  {
      m_Window = std::unique_ptr<Hazel::Window>(Window::Create());
  };

  Application::~Application()
  {
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
