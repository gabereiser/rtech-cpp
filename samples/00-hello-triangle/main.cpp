#include <rtech.h>

using namespace rtech;
using namespace rtech::math;

int main(int argc, char** argv)
{
    std::string title = "rTech - 00-hello-triangle";

    Engine& engine = Engine::instance();

    if (!engine.createWindow(title, 1280, 720, false)) {
        Logger::log(Logger::LEVEL_WARN, "Couldn't create window, aborting...");
        engine.quit();
        return 0;
    }
    engine.init();

    engine.run();
    
    engine.quit();

    std::cout << "Goodbye" << std::endl;
}