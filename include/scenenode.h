#pragma once

#include "common.h"

namespace rtech
{
    class API SceneNode
    {
        protected:
        std::vector<Ptr<SceneNode>> _children;
        Ptr<SceneNode> _parent;

        public:
        API SceneNode();
        API ~SceneNode();
        API SceneNode(const SceneNode&)=default;
        API SceneNode(SceneNode&&)=default;
        API void addChild(Ptr<SceneNode> node);
        API void removeChild(Ptr<SceneNode> node);
        API void clearChildren();
    };
}