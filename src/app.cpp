#include <app.h>
#include <engine.h>

namespace rtech
{
    API
    App::App(){}
    App::~App(){}

    API
    void App::init(){}

    API
    void App::render(){}

    API
    void App::update(){}

    API
    void App::exit(){ Engine::instance().quit(); }
}