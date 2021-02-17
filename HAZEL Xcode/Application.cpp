#include <sstream>

#include "Application.h"
#include "log.h"
#include "spdlog/spdlog.h"
#include "ApplicationEvent.h"
#include "MouseEvent.h"
#include "GLFW/glfw3.h"
#include "Layer.h"

#define GL_SILENCE_DEPRECATION

namespace Hazel {

    class ExampleLayer: public Layer
    {
    public:
        ExampleLayer()
            : Layer("Example Layer")
        {}
        
        void  OnUpdate() override
        {
            HZ_INFO("Example Layer::Update");
        }
        
        void  OnEvent(Event &event) override
        {
            HZ_TRACE("{0}", event );
        }
    };


#define BIND_EVENT_FN(x)std::bind(&x, this, std::placeholders::_1)
    Application::Application()
    {
        m_Window = std::unique_ptr<Hazel::Window>(Window::Create());
        m_Window->SetEventCallback( BIND_EVENT_FN( Application::OnEvent ) );
        
        PushLayer(new ExampleLayer());
        
    };

    Application::~Application()
    {
    };
    
    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer( layer );
    }
    void Application::PushOverlay (Layer *layer)
    {
        m_LayerStack.PushOverlay( layer );
    }

    void Application::OnEvent( Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        
        HZ_CORE_INFO( "{0}", e );
        
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
        
    };

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }

    void Application::Run()
    {
        while (m_Running){
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate();
            
            m_Window->OnUpdate();
        };
    };
}
