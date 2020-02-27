#pragma once

#include <common.h>

namespace rtech
{
    class API App
    {
        template <typename T>
        friend class Singleton;

        public:
        virtual void init();
        virtual void render();
        virtual void update();
        virtual void exit();

        protected:
        App();
        ~App();
    };
}