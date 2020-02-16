#pragma once

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <iostream>

#include <memory>

#include <glm/ext.hpp>
#include <SDL.h>
#include <bx/bx.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>


#if defined(_MSC_VER)
    //  Microsoft 
    #include <functional>
    #define API __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#else
    //  The rest of the world
    #define API __attribute__((visibility("default")))
#endif


namespace rtech {
    class Engine;
    class Scene;
}