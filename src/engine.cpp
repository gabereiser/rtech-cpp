#include <engine.h>
#include <SDL.h>
#include <SDL_syswm.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/bx.h>
#include <bx/mutex.h>
#include <bx/thread.h>

int _counter;
int _width, _height = 0;

inline bool sdlSetWindow(SDL_Window* window)
{
    SDL_SysWMinfo wmi;
    SDL_VERSION(&wmi.version);
    if (!SDL_GetWindowWMInfo(window, &wmi)) {
        return false;
    }

    bgfx::PlatformData pd;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
    pd.ndt = wmi.info.x11.display;
    pd.nwh = (void*)(uintptr_t)wmi.info.x11.window;
#elif BX_PLATFORM_OSX
    pd.ndt = NULL;
    pd.nwh = wmi.info.cocoa.window;
#elif BX_PLATFORM_WINDOWS
    pd.ndt = NULL;
    pd.nwh = wmi.info.win.window;
#elif BX_PLATFORM_STEAMLINK
    pd.ndt = wmi.info.vivante.display;
    pd.nwh = wmi.info.vivante.window;
#endif // BX_PLATFORM_
    pd.context = NULL;
    pd.backBuffer = NULL;
    pd.backBufferDS = NULL;
    bgfx::setPlatformData(pd);

    return true;
};

static void sdlDestroyWindow(SDL_Window* window)
{
    if(!window) 
        return;
#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
#		if ENTRY_CONFIG_USE_WAYLAND
    wl_egl_window *win_impl = (wl_egl_window*)SDL_GetWindowData(window, "wl_egl_window");
    if(win_impl)
    {
        SDL_SetWindowData(window, "wl_egl_window", nullptr);
        wl_egl_window_destroy(win_impl);
    }
#		endif
#	endif
    SDL_DestroyWindow(window);
};

static int32_t threadMain(bx::Thread* _thread, void* _userData)
{
    while (1) {
        bgfx::setViewRect(0, 0, 0, uint16_t(_width), uint16_t(_height));
        bgfx::touch(0);
        bgfx::dbgTextClear();
        bgfx::dbgTextPrintf(0, 1, 0x4f, "Counter:%d", _counter++);
        bgfx::frame();
    }
    return 0;
};


namespace rtech {
    static SDL_Window* window = nullptr;
    
    bool _exit = false;

    static void reshape()
    {
        int w,h;
        SDL_GetWindowSize(window, &w, &h);
        SDL_Surface* surface = SDL_GetWindowSurface(window);
        
        bgfx::reset(w, h, BGFX_RESET_VSYNC);
    }
    API
    Engine::Engine() : _scene(std::make_shared<Scene>()) {
        
    }

    API
    Engine::~Engine() {

    }

    API
    bool Engine::createWindow(const std::string& title, const int& width, const int& height, const bool& fullscreen) {
        SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC);
        _width = width;
        _height = height;
        int32_t flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
        if (fullscreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        sdlSetWindow(window);
        bgfx::renderFrame();
        bgfx::init();
        bgfx::reset(_width, _height, BGFX_RESET_VSYNC);

        // Enable debug text.
        bgfx::setDebug(BGFX_DEBUG_TEXT /*| BGFX_DEBUG_STATS*/);

        // Set view 0 clear state.
        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH | BGFX_CLEAR_STENCIL, 0x303030ff, 1.0f, 0);
        bgfx::frame();
        return true;
    }

    API
    void Engine::init() {
        ASSERT(window);
        this->_scene->init();
    }

    API
    void Engine::run() {
        
        _exit = false;
        SDL_Event event;
        while (!_exit) {
            bgfx::setViewRect(0, 0, 0, uint16_t(_width), uint16_t(_height));
            bgfx::touch(0);
            bgfx::dbgTextClear();
            bgfx::dbgTextPrintf(0, 0, 0x4f, "Counter:%d", _counter++);
            bgfx::frame();
            
            while (SDL_PollEvent(&event)) {

                switch (event.type) {
                case SDL_QUIT:
                    _exit = true;
                    break;
                case SDL_KEYDOWN: {
                    const SDL_KeyboardEvent& kev = event.key;
                    SDL_Keycode code = SDL_GetKeyFromScancode(kev.keysym.scancode);
                    switch(code){
                        case SDLK_ESCAPE:
                            _exit = true;
                            break;
                    };
                    break;
                }
                case SDL_WINDOWEVENT: {
                    const SDL_WindowEvent& wev = event.window;
                    switch (wev.event) {
                        case SDL_WINDOWEVENT_RESIZED:
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            _width = wev.data1;
                            _height = wev.data2;
                            bgfx::reset(wev.data1, wev.data2, BGFX_RESET_VSYNC);
                            break;
                        case SDL_WINDOWEVENT_CLOSE:
                            _exit = true;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        bgfx::shutdown();

        

        _scene->clear();
        sdlDestroyWindow(window);
        SDL_Quit();
    }

    API
    void Engine::quit() {
        _exit = true;
    }

    API
    void Engine::setUpdateFunc(const std::function<void()> callback) {
        this->_update_cb = callback;
    }

    API
    void Engine::setRenderFunc(const std::function<void()> callback) {
        this->_render_cb = callback;
    }
}