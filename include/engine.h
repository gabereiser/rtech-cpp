#pragma once

#include <app.h>
#include <singleton.h>
#include <scene.h>
#include <package_manager.h>
#include <SDL.h>
extern SDL_Window* get_sdl_window();

namespace rtech {
    class API Engine : public Singleton<Engine> {
        template <typename T>
        friend class Singleton;
        

        protected:
        Engine();
        ~Engine();

        public:
        bool createWindow(const std::string& title, const int& width, const int& height, const bool& fullscreen);
        void init(const Ref<App> app);
        void run();
        void quit();
        void setUpdateFunc(const std::function<void()> callback);
        void setRenderFunc(const std::function<void()> callback);

        private:
        std::function<void()> _update_cb;
        std::function<void()> _render_cb;
        Ref<Scene> _scene;
        Ref<App> _app;
    };
}