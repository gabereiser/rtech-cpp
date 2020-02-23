#pragma once

#include "common.h"
#include "scenenode.h"

namespace rtech 
{
    class API Scene {
        private:
        Ref<SceneNode> _rootNode;

        public:
        Scene();
        ~Scene();
        void init();
        void clean();
    };
}