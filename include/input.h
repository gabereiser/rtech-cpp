#pragma once

#include <common.h>
#include <singleton.h>

namespace rtech
{
    class API Input : public Singleton<Input>
    {
        friend class Singleton;
        
        private:

        protected:
        Input();
        ~Input();

        public:
        
    };
}