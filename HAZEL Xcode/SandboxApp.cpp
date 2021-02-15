#include <iostream>
#include <sstream>
#include "spdlog/spdlog.h"
#include "Application.h"
#include "log.h"
#include "ApplicationEvent.h"

class Sandbox : public Hazel::Application
{
  public: 
    Sandbox()
    {

    };

    ~Sandbox()
    {

    };

};

int main()
{
     Hazel::Log::Init();
    HZ_CORE_WARN("Initalized Core Log!");

  /*  HZ_TRACE("Trace!");
    HZ_INFO("Info!");
    HZ_WARN("Warn!");
    HZ_ERROR("Error!");
    HZ_WARN("Initalized APP!");
   */

    // std::cout << "Welcome to Hazel, press any key to continue..." << '\n';

    // std::cin.get();

    Sandbox* sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
    return 0;
}
