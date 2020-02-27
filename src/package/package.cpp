#include <package/package.h>

#include <iostream>
#include <fstream>
#include <zip.h>

namespace rtech
{
    namespace package
    {
        
        static zip_t* rzip_open(const char *name, int flags) {
            int err = 0;
            auto *z = zip_open(name, 0, &err);

            return z;
        }

        API
        Package::~Package()
        {
            if(this->p != nullptr)
            {
                this->close();
            }
        }

        API
        Package::Package(const std::filesystem::path& path) :
            p(rzip_open(path.c_str(), 0))
        {
        }

        API
        void Package::close()
        {
            zip_t *z = (zip_t*)this->p;
            zip_close(z);
            this->p = nullptr;
        }

        API
        Ref<Actor> Package::getActor(const std::filesystem::path& path)
        {
            return std::make_shared<Actor>();
        }

        API
        Ref<Font> Package::getFont(const std::filesystem::path& path)
        {
            return std::make_shared<Font>();
        }

        API
        Ref<Material> Package::getMaterial(const std::filesystem::path& path)
        {
            return std::make_shared<Material>();
        }

        API
        Ref<Mesh> Package::getMesh(const std::filesystem::path& path)
        {
            return std::make_shared<Mesh>();
        }

        API
        Ref<Shader> Package::getShader(const std::filesystem::path& path)
        {
            return std::make_shared<Shader>();
        }

        API
        Ref<Texture> Package::getTexture(const std::filesystem::path& path)
        {
            return std::make_shared<Texture>();
        }

        API
        bool Package::validate()
        {
            return true;
        }
    }
}