#pragma once

#include <common.h>
#include <textures/texture.h>
#include <materials/material.h>
#include <geometry/mesh.h>
#include <types/font.h>
#include <types/shader.h>
#include <actor.h>
using namespace rtech::textures;
using namespace rtech::geometry;
using namespace rtech::materials;
using namespace rtech::types;

namespace rtech
{
    namespace package
    {
        class API Package
        {
            public:
            Package(const std::filesystem::path& path);
            ~Package();
            void close();
            void count();
            Ref<Texture> getTexture(const std::filesystem::path& path);
            Ref<Mesh> getMesh(const std::filesystem::path& path);
            Ref<Font> getFont(const std::filesystem::path& path);
            Ref<Shader> getShader(const std::filesystem::path& path);
            Ref<Material> getMaterial(const std::filesystem::path& path);
            Ref<Actor> getActor(const std::filesystem::path& path);
            bool validate();

            private:
            void* p;
        };
    }
}