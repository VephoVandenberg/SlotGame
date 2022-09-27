#pragma once

namespace gameModule
{
    class Texture
    {
    public:
	Texture() = default;
	Texture(const Texture& texture) = default;
	Texture& operator=(const Texture& texture) = default;

	
	Texture(const char *path);
	~Texture();
	void bind() const;
	void init(const char *path);

	inline bool getStatus() const { return m_isInitialized; }
	
    private:
	unsigned int ID;
	bool m_isInitialized = false;
    };
}
