#pragma once

#include "common.h"
#include "scenenode.h"

namespace rtech 
{
    class Scene {
        private:
        Ptr<SceneNode> _rootNode;

        public:
        API Scene();
        API ~Scene();
        API void init();
        API void clean();
    };
}