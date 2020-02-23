#pragma once

#include "common.h"

namespace rtech
{
    class API SceneNode
    {
        protected:
        std::vector<Ref<SceneNode>> _children;
        Ref<SceneNode> _parent;

        public:
        SceneNode();
        ~SceneNode();
        SceneNode(const SceneNode&)=default;
        SceneNode(SceneNode&&)=default;
        void addChild(Ref<SceneNode> node);
        void removeChild(Ref<SceneNode> node);
        void clearChildren();
    };
}