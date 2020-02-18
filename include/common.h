/// @ref rtech
/// @file common.h
/// @defgroup rtech
/// @mainpage rTech Graphics Toolkit
/// The rTech Graphics Toolkit is a cross-platform thread-safe C++ library.

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

/*! \namespace rtech
 */
namespace rtech {
    /*! \struct Vec2
     */
    typedef glm::vec2 Vec2;
    /*! \struct Vec3
     */
    typedef glm::vec3 Vec3;
    /*! \struct Vec4
     */
    typedef glm::vec4 Vec4;
    /*! \struct Matrix
     */
    typedef glm::mat4 Matrix;
    /*! \struct Matrix3
     */
    typedef glm::mat3 Matrix3;
    /*! \struct Quaternion
     */
    typedef glm::quat Quaternion;
    class Engine;
    class Scene;
    class SceneNode;

    template <class T>
    using Ptr = std::shared_ptr<T>;
}