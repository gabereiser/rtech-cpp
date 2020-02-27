#include <common.h>
#include <scenenode.h>
#include <scene.h>

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
    }

    API
    void Scene::clear() {
        _rootNode->clearChildren();
    }
}