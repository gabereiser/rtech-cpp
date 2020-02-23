#pragma once

#include <singleton.h>
#include <scene.h>

namespace rtech {
    class API Engine: public Singleton<Engine> {
        friend class Singleton;
        private:
        std::function<void()> _update_cb;
        std::function<void()> _render_cb;
        Ref<Scene> _scene;

        protected:
        Engine();
        ~Engine();

        public:
        bool createWindow(const std::string& title, const int& width, const int& height, const bool& fullscreen);
        void init();
        void run();
        void quit();
        void setUpdateFunc(const std::function<void()> callback);
        void setRenderFunc(const std::function<void()> callback);
    };
}