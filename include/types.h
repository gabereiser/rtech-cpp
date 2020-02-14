#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_net.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#endif

#ifdef __linux__
#include <gl.h>
#endif

#ifdef __WIN32__
#include <gl.h>
#endif

#include <glm/glm.hpp>
#include "config.h"

using vec2    = glm::vec2;
using vec3    = glm::vec3;
using vec4    = glm::vec4;
using quat    = glm::quat;
using matrix  = glm::mat4;
using matrix3 = glm::mat3;
using matrix2 = glm::mat2;

namespace rtech {
    
}