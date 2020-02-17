#include "scenenode.h"

namespace rtech
{
    API SceneNode::SceneNode() {
    }
    

    API SceneNode::~SceneNode() {}


    API
    void SceneNode::addChild(Ptr<SceneNode> node)
    {
        node->_parent.reset(this);
        _children.push_back(node);
    }

    API
    void SceneNode::removeChild(Ptr<SceneNode> node)
    {
        for( auto iter = _children.begin(); iter != _children.end(); ++iter )
        {
            if( *iter == node )
            {
                _children.erase( iter );
                break;
            }
        }
    }

    API
    void SceneNode::clearChildren()
    {
        _children.clear();
    }

}