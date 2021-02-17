#pragma once

#include "Window.h"
#include "ApplicationEvent.h"
#include "Layer.h"
#include "LayerStack.h"

namespace Hazel {

    class Application
    {
    public:
      Application();
      virtual ~Application();

      void Run();
        
      void OnEvent( Event& e);
        
        void PushLayer( Layer* layer );
        void PushOverlay( Layer* layer);
        
    private:
        bool OnWindowClose( WindowCloseEvent& e );
        
        std::unique_ptr<Hazel::Window> m_Window;
        bool m_Running = true;
        
        LayerStack m_LayerStack;
    };
}
