#pragma once

#include <map>
#include <string>

#include "Shader.h"

namespace gameModule
{
    class ResourceManager
    {
    public:
	static void loadShader(const char* vPath, const char *fPath, const char *shaderName);
	static Shader& getShader(const char *shaderName);
	
	ResourceManager() = delete;
	ResourceManager(const ResourceManager& manager) = delete;
	~ResourceManager() = delete;
	ResourceManager& operator=(const ResourceManager& manager) = delete;

    private:
	static std::map<std::string, Shader> shaders;
    };
}
