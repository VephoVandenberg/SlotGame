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
	~ResourceManager() = delete;

    private:
	static std::map<std::string, Shader> shaders;
    };
}
