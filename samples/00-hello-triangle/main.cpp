#include <rtech.h>

using namespace rtech;

int main(int argc, char** argv)
{
    Engine& engine = Engine::instance();
    engine.init();
    Vec3 v = Vec3{0.0f, 0.0f, 0.0f};
    Vec3 v2 = Vec3{1.0f, 1.0f, 1.0f};
    auto v3 = v + v2;
    std::cout << "X:" << v3.x << " Y:" << v3.y << " Z:" << v3.z << std::endl;
    engine.quit();
    std::cout << "Goodbye" << std::endl;
}