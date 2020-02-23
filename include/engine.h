#pragma once

#include "common.h"
#include "scene.h"

namespace rtech {
    class API Engine {
        private:
        std::function<void()> _update_cb;
        std::function<void()> _render_cb;
        Ref<Scene> _scene;


        public:
        Engine();
        ~Engine();
        Engine(const Engine&) = delete;
        Engine(Engine&&) = delete;
        Engine& operator=(const Engine&) = delete;
        Engine& operator=(Engine&&) = delete;
        static Engine& instance();
        bool createWindow(const std::string& title, const int& width, const int& height, const bool& fullscreen);
        void init();
        void run();
        void quit();
        void setUpdateFunc(const std::function<void()> callback);
        void setRenderFunc(const std::function<void()> callback);
    };
}