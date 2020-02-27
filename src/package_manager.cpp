#include <package_manager.h>
#include <map>

using namespace rtech::package;

namespace rtech
{
    API
    PackageManager::PackageManager() : _packages()
    {

    }

    API
    PackageManager::~PackageManager()
    {
        _packages.clear();
    }

    API
    void PackageManager::addPackage(const std::string& name, const std::filesystem::path& path)
    {
        if(_packages[name] != nullptr)
        {
            throw std::string("Package with name already exists!");
        }

        Ref<Package> p = std::make_shared<Package>(path);
        _packages[name] = p;
    }

    API
    Ref<Package> PackageManager::getPackage(const std::string& name)
    {
        if(_packages[name])
        {
            return _packages[name];
        }
        else
        {
            return nullptr;
        }
    }
}