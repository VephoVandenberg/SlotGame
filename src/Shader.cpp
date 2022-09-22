#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Shader.h"

using namespace gameModule;

Shader::Shader(const char *vPath, const char *fPath)
{
    std::string vSrc, fSrc;
    std::ifstream vFile, fFile;

    vFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
	vFile.open(vPath);
	fFile.open(fPath);

	std::stringstream vStream, fStream;
		
	vStream << vFile.rdbuf();
	fStream << fFile.rdbuf();

	vFile.close();
	fFile.close();

	vSrc = vStream.str();
	fSrc = fStream.str();
    }
    catch (std::ifstream::failure e)
    {
	std::cout << "Could not read files" << std::endl;
    }

    char infolog[512];
    int success;

    const char* vStr = vSrc.c_str();
    const char* fStr = fSrc.c_str();

    unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vStr, NULL);
    glCompileShader(vShader);
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
	glGetShaderInfoLog(vShader, 512, NULL, infolog);
	std::cout << "VERTEX:" << infolog;
    }

    unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fStr, NULL);
    glCompileShader(fShader);
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
	glGetShaderInfoLog(fShader, 512, NULL, infolog);
	std::cout << "FRAGMENT:" << infolog;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vShader);
    glAttachShader(ID, fShader);
    glLinkProgram(ID);

    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::setUniform1i(const char *uniform, int value)
{
    glUniform1f(glGetUniformLocation(ID, uniform), value);
    glUseProgram(ID);
}

void Shader::setUniform4m(const char *uniform, glm::mat4 matrix)
{
    glUniformMatrix4fv(glGetUniformLocation(ID, uniform), 1, false, glm::value_ptr(matrix));
    glUseProgram(ID);
}

void Shader::setUniform3v(const char *uniform, glm::vec3 vector)
{
    glUniform3f(glGetUniformLocation(ID, uniform), vector.x, vector.y, vector.z);
    glUseProgram(ID);
}
