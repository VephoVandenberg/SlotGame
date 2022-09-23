#include "ResourceManager.h"

using namespace gameModule;

std::map<std::string, Shader> ResourceManager::shaders;

void ResourceManager::loadShader(const char *vPath, const char *fPath, const char *shaderName)
{
    Shader shader(vPath, fPath);
    shaders[shaderName] = shader;
}

Shader& ResourceManager::getShader(const char *shaderName)
{
    return shaders[shaderName];
}
