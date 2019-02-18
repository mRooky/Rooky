/*
 * PluginTexture.h
 *
 *  Created on: Nov 21, 2018
 *      Author: rookyma
 */

#ifndef PLUGIN_PLUGINTEXTURE_H_
#define PLUGIN_PLUGINTEXTURE_H_

#include <cstdio>
#include <cstdint>

namespace Plugin
{

class Texture
{

public:
	enum class Format : uint32_t
	{
		TYPE_ALPHA = 0,
		TYPE_GRAY = TYPE_ALPHA + 1,
		TYPE_GRAY_ALPHA = TYPE_GRAY + 1,
		TYPE_RGB = TYPE_GRAY_ALPHA + 1,
		TYPE_RGB_ALPHA = TYPE_RGB + 1,
		TYPE_UNKNOWN = ~0U
	};

public:
	Texture(void);
	virtual ~Texture(void);

public:
	virtual bool Load(const char* file) = 0;
	virtual bool Save(const char* file) = 0;

public:
	uint8_t* Allocate(size_t size);

public:
	inline size_t GetSize(void) const { return mSize; }
	inline Format GetFormat(void) const { return mFormat; }
	inline const uint8_t* GetData(void) const { return m_data; }

public:
	inline uint32_t GetWidth(void) const { return mWidth; }
	inline uint32_t GetHeight(void) const { return mHeight; }
	inline uint32_t GetBitDepth(void) const { return mBitDepth; }
	inline uint32_t GetChannels(void) const { return mChannels; }

protected:
	uint32_t mWidth = 0;
	uint32_t mHeight = 0;
	uint32_t mBitDepth = 0;
	uint32_t mChannels = 0;

protected:
	size_t mSize = 0;
	Format mFormat = Format::TYPE_UNKNOWN;

private:
	uint8_t* m_data = nullptr;
};

} /* namespace Plugin */

#endif /* PLUGIN_PLUGINTEXTURE_H_ */
