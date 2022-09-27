#include <iostream>
#include "ResourceManager.h"

using namespace gameModule;

std::unordered_map<std::string, Shader> ResourceManager::shaders;
std::unordered_map<std::string, Texture> ResourceManager::textures;

void ResourceManager::loadShader(const char *vPath, const char *fPath, const char *shaderName)
{
    Shader shader(vPath, fPath);
    shaders[shaderName] = shader;
}

Shader& ResourceManager::getShader(const char *shaderName)
{
    return shaders[shaderName];
}

void ResourceManager::loadTexture(const char *path, const char *textureName)
{
    Texture texture(path);
    textures[textureName] = texture;
}

Texture& ResourceManager::getTexture(const char *textureName)
{
    return textures[textureName];
}
