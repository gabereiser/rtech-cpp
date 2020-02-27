#pragma once

#include <common.h>
#include <singleton.h>
#include <package/package.h>

namespace rtech
{
    class API PackageManager : public Singleton<PackageManager> {
        template <typename T>
        friend class Singleton;

        protected:
        PackageManager();
        ~PackageManager();

        public:
        void addPackage(const std::string& name, const std::filesystem::path& path);
        Ref<package::Package> getPackage(const std::string& name);

        private:
        std::map<std::string, Ref<package::Package>> _packages;
    };
}