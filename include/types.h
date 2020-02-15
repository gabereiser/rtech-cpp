#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <iostream>

#include "bgfx/bgfx.h"

#include "config.h"

#if defined(_MSC_VER)
    //  Microsoft 
    #define API __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#else
    #define API __attribute__((visibility("default")))
#endif


namespace rtech {
    
}