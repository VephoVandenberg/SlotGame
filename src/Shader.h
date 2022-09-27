#pragma once

#include <glm/glm.hpp>

namespace gameModule
{
    class Shader
    {
    public:
	Shader() = default;
	~Shader() = default;
	Shader(const Shader& shader) = default;
	Shader(const char *vPath, const char *fPath);
	

	void use();
	void setUniform1i(const char *uniform, int value);
	void setUniform4m(const char *uniform, glm::mat4 matrix);
	void setUniform3v(const char *uniform, glm::vec3 vector);;
	
    private:
	unsigned int ID;
    };
}
    
