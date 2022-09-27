#pragma once

#include <unordered_map>
#include <string>

#include "Shader.h"
#include "Texture.h"

namespace gameModule
{
    class ResourceManager
    {
    public:
	static void loadShader(const char* vPath, const char *fPath, const char *shaderName);
	static Shader& getShader(const char *shaderName);

	static void loadTexture(const char *path, const char *textureName);
	static Texture& getTexture(const char *textureName);
	
	ResourceManager() = delete;
	ResourceManager(const ResourceManager& manager) = delete;
	~ResourceManager() = delete;
	ResourceManager& operator=(const ResourceManager& manager) = delete;

    private:
	static std::unordered_map<std::string, Shader> shaders;
	static std::unordered_map<std::string, Texture> textures;
    };
}
