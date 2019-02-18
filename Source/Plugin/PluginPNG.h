/*
 * PluginPNG.h
 *
 *  Created on: Nov 17, 2018
 *      Author: rookyma
 */

#ifndef PLUGIN_PLUGINPNG_H_
#define PLUGIN_PLUGINPNG_H_

#include "PluginTexture.h"
#include <png.h>

namespace Plugin
{

class PNG : public Texture
{
public:
	PNG(void);
	virtual ~PNG(void) override;

public:
	virtual bool Load(const char* file) override;
	virtual bool Save(const char* file) override;

private:
	bool ReadFile(FILE* file);
	bool CheckFile(FILE* file);
	bool InitReader(png_structp& png_ptr, png_infop& info_ptr);
	void GetInfo(png_structp png_ptr, png_infop info_ptr);
	void ReadData(png_structp png_ptr, png_infop info_ptr);

private:
	bool WriteFile(FILE* file);
	bool InitWriter(png_structp& png_ptr, png_infop& info_ptr);
	void SetInfo(png_structp png_ptr, png_infop info_ptr);
	void WriteData(png_structp png_ptr, png_infop info_ptr);

public:
	static const char* GetColorTypeName(uint8_t type);

private:
	size_t m_rowbytes = 0;

private:
	uint8_t m_colorType = 0;
	uint8_t m_filterMethod = 0;
	uint8_t m_compressionType = 0;
	uint8_t m_interlaceType = 0;

};

} /* namespace Plugin */

#endif /* PLUGIN_PLUGINPNG_H_ */
