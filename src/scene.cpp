#include "scenenode.h"
#include "scene.h"

namespace rtech {

    API
    Scene::Scene() {

    }

    API
    Scene::~Scene() {

    }

    API
    void Scene::init() {
        _rootNode = std::make_shared<SceneNode>();
        std::cout << "Scene initialized" << std::endl;
    }

    API
    void Scene::clean() {
        _rootNode->clearChildren();
    }
}