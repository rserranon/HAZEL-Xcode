#pragma once

#include "Window.h"

namespace Hazel {

    class Application
    {
    public:
      Application();
      virtual ~Application();

      void Run();
        
    private:
        std::unique_ptr<Hazel::Window> m_Window;
        bool m_Running = true;
    };
}
