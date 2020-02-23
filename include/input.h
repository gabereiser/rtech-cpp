#pragma once

#include <common.h>
#include <singleton.h>

namespace rtech
{
    class API Input : public Singleton<Input>
    {
        private:

        protected:
        Input();
        ~Input();

        public:
        
    };
}