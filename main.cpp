#include "src/Application.h"

const unsigned int width = 800;
const unsigned int height = 800;

int main(int argc, char **argv)
{
    auto app = new gameModule::Application("Application", width, height);
    app->run();
    delete app;
    
    return 0;
}
