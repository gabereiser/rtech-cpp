#pragma once

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <iostream>
#include <memory>
#include <vector>

#if defined(_MSC_VER)
    //  Microsoft 
    #include <functional>
    #define API __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#else
    //  The rest of the world
    #define API __attribute__((visibility("default")))
#endif


#include <glm/ext.hpp>

namespace rtech {
    class Engine;
    class Scene;
    class SceneNode;
}

template <class T>
using Ptr = std::shared_ptr<T>;

typedef glm::vec2 Vec2;
typedef glm::vec3 Vec3;
typedef glm::vec4 Vec4;
typedef glm::mat4 Matrix;
typedef glm::mat3 Matrix3;
typedef glm::quat Quaternion;

typedef nullptr_t NULLPTR;
typedef int32_t i32;
typedef int16_t i16;
typedef float_t f32;
typedef double_t f64;