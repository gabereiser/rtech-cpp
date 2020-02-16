#include "rtech.h"

using namespace rtech;

int main(int argc, char** argv) {
    std::cout << "rTech : ";
    std::cout << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << " : ";
    std::cout << GIT_COMMIT_HASH << " : " << GIT_BRANCH << " : " << TODAY << std::endl;
    Engine& engine = Engine::instance();
    engine.init();
    engine.run();
    engine.quit();
    return 0;
}