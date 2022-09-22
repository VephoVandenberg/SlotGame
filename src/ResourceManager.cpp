#include "ResourceManager.h"

using namespace gameModule;

std::map<std::string, Shaders>> ResourceManageres::shaders;

void ResourceManager::loadShader(const char *vPath, const char *fPath, const char *shaderName)
{
    Shader shader(vPath, fPath);
    shaders[shaderName] = shader;
}

Shader& ResourceManager::getShader(const char *shaderName)
{
    retrun shaders[shaderName];
}
