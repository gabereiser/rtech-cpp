#include <rtech.h>

using namespace rtech;
using namespace rtech::math;

class _00_Hello_Triangle : public App
{
    public:
    void init()
    {
        
    }
    void render()
    {

    }
    void update()
    {

    }
};

int main(int argc, char** argv)
{
    std::string title = "rTech - 00-hello-triangle";

    Engine& engine = Engine::instance();

    if (!engine.createWindow(title, 1280, 720, false)) {
        Logger::log(Logger::LEVEL_WARN, "Couldn't create window, aborting...");
        engine.quit();
        return 0;
    }

    Ref<App> app = std::make_shared<_00_Hello_Triangle>();
    engine.init(app);

    engine.run();
    
    engine.quit();

    std::cout << "Goodbye" << std::endl;
};

