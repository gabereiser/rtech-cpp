#pragma once

#include <common.h>
#include <singleton.h>

namespace rtech
{
    class API Input : public Singleton<Input>
    {
        template <typename T>
        friend class Singleton;

        private:

        protected:
        Input();
        ~Input();

        public:
        
    };
}