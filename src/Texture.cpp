#include <GL/glew.h>

#include "stb_image.h"
#include "Texture.h"

using namespace gameModule;

Texture::Texture(const char *path)
{
    init(path);
}

Texture::~Texture()
{
}

void Texture::bind() const
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::init(const char *path)
{
    m_isInitialized = true;

    int width, height, nrChanels;
  
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    unsigned char *data = stbi_load(path, &width, &height, &nrChanels, 0);
    if (data)
    {	    
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);
}
