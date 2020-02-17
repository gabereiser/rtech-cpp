#pragma once

#include "common.h"
#include "scene.h"

namespace rtech {
    class Engine {
        private:
        std::function<void()> _update_cb;
        std::function<void()> _render_cb;
        Ptr<Scene> _scene;


        public:
        API Engine();
        API ~Engine();
        API Engine(const Engine&) = delete;
        API Engine(Engine&&) = delete;
        API Engine& operator=(const Engine&) = delete;
        API Engine& operator=(Engine&&) = delete;
        API static Engine& instance();
        API void init();
        API void run();
        API void quit();
        API void setUpdateFunc(const std::function<void()> callback);
        API void setRenderFunc(const std::function<void()> callback);
    };
}