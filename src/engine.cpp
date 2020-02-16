#include "engine.h"

static rtech::Engine _engine{};

namespace rtech {
    
    API
    Engine::Engine() : _scene{new Scene()} {

    }

    API
    Engine::~Engine() {

    }

    API
    Engine& Engine::instance() {
        return _engine;
    };

    API
    void Engine::init() {
        this->_scene->init();
    };

    API
    void Engine::run() {

    };

    API
    void Engine::quit() {
        
    };

    API
    void Engine::setUpdateFunc(const std::function<void()> callback) {
        this->_update_cb = callback;
    }

    API
    void Engine::setRenderFunc(const std::function<void()> callback) {
        this->_render_cb = callback;
    }

}