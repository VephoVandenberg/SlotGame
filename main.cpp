#include "src/Application.h"

const unsigned int width = 1100;
const unsigned int height = 600;

int main(int argc, char **argv)
{
    auto app = new gameModule::Application("Application", width, height);
    app->run();
    delete app;
    
    return 0;
}
