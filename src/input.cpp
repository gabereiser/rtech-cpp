#include <input.h>
#include <engine.h>

using namespace rtech::math;

namespace rtech
{
    API
    Input::Input(){}

    API
    Input::~Input(){}

    API
    void Input::update()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type)
        {
            default:
            break;
        }
    }

    API
    void Input::centerMouse()
    {
        SDL_Window* window = get_sdl_window();
        int w, h;
        SDL_GetWindowSize(window, &w, &h);

        SDL_WarpMouseInWindow(window, w/2, h/2);
    }

    API
    Vector2 Input::getMousePos()
    {
        int x,y,state;
        state = SDL_GetRelativeMouseState(&x, &y);
        return Vector2{float(x), float(y)};
    }

    API
    Vector2 Input::getMousePosAbsolute()
    {
        int x,y,state;
        state = SDL_GetGlobalMouseState(&x, &y);
        return Vector2{float(x), float(y)};
    }

    API
    void Input::setMousePos(const Vector2& pos)
    {
        SDL_WarpMouseGlobal(int(pos.x), int(pos.y));
    }
}