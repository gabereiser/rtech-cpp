/*! \ref rtech
 *  \file common.h
 *  \defgroup rtech
 *  \mainpage rTech Graphics Toolkit
 * The rTech Graphics Toolkit is a cross-platform thread-safe C++ library.
 */
#ifndef _COMMON_H
#define _COMMON_H

#pragma once

// NOMINMAX makes sure that windef.h doesn't add macros min and max
#ifdef WIN32
    #define NOMINMAX
#endif

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <iostream>
#include <memory>
#include <cassert>
#include <cmath>
#include <string>
#include <filesystem>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <limits>
#include <functional>
#include <bitset>
#include <typeinfo>
#include <thread>
#include <mutex>
#include <chrono>
#include <logger.h>

using std::memcpy;
using std::fabs;
using std::sqrt;
using std::cos;
using std::sin;
using std::tan;
using std::isspace;
using std::isdigit;
using std::toupper;
using std::tolower;
using std::size_t;
using std::min;
using std::max;
using std::modf;
using std::atoi;


#ifdef WIN32

    //  Microsoft 
    #ifdef DLL
    #define API __declspec(dllexport)
    #else
    #define API __declspec(dllimport)
    #endif
#else
    //  The rest of the world
    #define API __attribute__((visibility("default")))
#endif

// Assert macros.
#ifdef DEBUG
#define ASSERT(expression) assert(expression)
#else
#define ASSERT(expression)
#endif

// Current function macro.
#ifdef WIN32
#define __current__func__ __FUNCTION__
#else
#define __current__func__ __func__
#endif
#if defined(WIN32) && defined(_MSC_VER)
#define DEBUG_BREAK() __debugbreak()
#else
#define DEBUG_BREAK()
#endif

#define MATH_DEG_TO_RAD(x)          ((x) * 0.0174532925f)
#define MATH_RAD_TO_DEG(x)          ((x)* 57.29577951f)
#define MATH_RANDOM_MINUS1_1()      ((2.0f*((float)rand()/RAND_MAX))-1.0f)      // Returns a random float between -1 and 1.
#define MATH_RANDOM_0_1()           ((float)rand()/RAND_MAX)                    // Returns a random float between 0 and 1.
#define MATH_FLOAT_SMALL            1.0e-37f
#define MATH_TOLERANCE              2e-37f
#define MATH_E                      2.71828182845904523536f
#define MATH_LOG10E                 0.4342944819032518f
#define MATH_LOG2E                  1.442695040888963387f
#define MATH_PI                     3.14159265358979323846f
#define MATH_PIOVER2                1.57079632679489661923f
#define MATH_PIOVER4                0.785398163397448309616f
#define MATH_PIX2                   6.28318530717958647693f
#define MATH_EPSILON                0.000001f
#define MATH_CLAMP(x, lo, hi)       ((x < lo) ? lo : ((x > hi) ? hi : x))
#ifndef M_1_PI
#define M_1_PI                      0.31830988618379067154
#endif


#define _ERROR(...) do \
    { \
        rtech::Logger::log(rtech::Logger::LEVEL_ERROR, "%s -- ", __current__func__); \
        rtech::Logger::log(rtech::Logger::LEVEL_ERROR, __VA_ARGS__); \
        rtech::Logger::log(rtech::Logger::LEVEL_ERROR, "\n"); \
        DEBUG_BREAK(); \
        assert(0); \
        std::exit(-1); \
    } while (0)


// Warning macro.
#define _WARN(...) do \
    { \
        rtech::Logger::log(rtech::Logger::LEVEL_WARN, "%s -- ", __current__func__); \
        rtech::Logger::log(rtech::Logger::LEVEL_WARN, __VA_ARGS__); \
        rtech::Logger::log(rtech::Logger::LEVEL_WARN, "\n"); \
    } while (0)


/*! \namespace rtech
 */
namespace rtech {
    
    namespace math
    {
        class Matrix;
        class Vector2;
        class Vector3;
        class Vector4;
        class Quaternion;
        class Frustum;
        class Plane;
        class Ray;
        class BoundingSphere;
        class BoundingBox;
    }
    namespace types
    {
        class Font;
        class Shader;
    }
    namespace geometry
    {
        class Mesh;
    }
    namespace textures
    {
        class Texture;
    }
    namespace materials
    {
        class Material;
    }
    namespace package
    {
        class Package;
    }
    class App;
    class Logger;
    class PackageManager;
    class Engine;
    class Input;
    class Scene;
    class SceneNode;

    

    
}

extern void rprint(const char* format, ...);

template <typename T>
using Ref = std::shared_ptr<T>;


#endif