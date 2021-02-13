#include <sstream>

#include "Application.h"
#include "log.h"
#include "spdlog/spdlog.h"
#include "ApplicationEvent.h"
#include "MouseEvent.h"

namespace Hazel {

  Application::Application()
  {
  };

  Application::~Application()
  {
  };


  void Application::Run()
  {
    while (true){

        Hazel::WindowResizeEvent  we (1200, 720);
        HZ_TRACE(we);
        Hazel::MouseMovedEvent    me (50.0f, 50.0f);
        HZ_TRACE(me);
        Hazel::WindowResizeEvent  we2 (640, 200);
        if ( we2.IsInCategory(EventCategoryApplication) )
        {
            HZ_TRACE(we2);
        };

    };
  };
}
