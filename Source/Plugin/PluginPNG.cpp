/*
 * PluginPNG.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: rookyma
 */

#include "PluginPNG.h"
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>

static const int32_t PNG_SUCCESS = 0;
static const int32_t PNG_BYTES_TO_CHECK = 4;

namespace Plugin
{

void PngError(png_structp png_struct, png_const_charp)
{
	std::cout << "PNG ERROR" << std::endl;
	longjmp(png_jmpbuf(png_struct), 1);
}

void PngWarning(png_structp, png_const_charp)
{
	std::cout << "PNG WARNING" << std::endl;
}

PNG::PNG(void)
{
}

PNG::~PNG(void)
{
}

bool PNG::Load(const char* file)
{
	assert(file != nullptr);
	bool flag = false;
	FILE * fp = fopen(file, "rb");
	if (fp != nullptr)
	{
		flag = CheckFile(fp);
		if (flag == true)
		{
			flag = ReadFile(fp);
		}
		fclose(fp);
	}
	return flag;
}

bool PNG::CheckFile(FILE* file)
{
	bool is_png = false;
	uint8_t buffer[PNG_BYTES_TO_CHECK];
	size_t size = fread(buffer, 1, PNG_BYTES_TO_CHECK, file);
	if (size == PNG_BYTES_TO_CHECK)
	{
		int flag = png_sig_cmp(buffer, 0, PNG_BYTES_TO_CHECK);
		is_png = (flag == 0);
	}
	return is_png;
}

bool PNG::ReadFile(FILE* file)
{
	png_structp png_ptr = nullptr;
	png_infop info_ptr = nullptr;

	bool flag = InitReader(png_ptr, info_ptr);
	if(flag == true)
	{
		assert(png_ptr != nullptr && info_ptr != nullptr);

		png_init_io(png_ptr, file);
		png_set_sig_bytes(png_ptr, PNG_BYTES_TO_CHECK);
		png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, nullptr);

		GetInfo(png_ptr, info_ptr);
		ReadData(png_ptr, info_ptr);

		png_destroy_read_struct(&png_ptr, &info_ptr, nullptr);
		return true;
	}
	return false;
}

bool PNG::InitReader(png_structp& png_ptr, png_infop& info_ptr)
{
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, &PngError, &PngWarning);
	if (png_ptr == nullptr)
	{
		return false;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == nullptr)
	{
		png_destroy_read_struct(&png_ptr, nullptr, nullptr);
		return false;
	}

	int32_t flag = setjmp(png_jmpbuf(png_ptr));
	if (flag != PNG_SUCCESS)
	{
		png_destroy_read_struct(&png_ptr, &info_ptr, nullptr);
		return false;
	}
	return true;
}

void PNG::GetInfo(png_structp png_ptr, png_infop info_ptr)
{
	mWidth = png_get_image_width(png_ptr, info_ptr);
	mHeight = png_get_image_height(png_ptr, info_ptr);
	mBitDepth = png_get_bit_depth(png_ptr, info_ptr);
	mChannels = png_get_channels(png_ptr, info_ptr);

	m_colorType = png_get_color_type(png_ptr, info_ptr);

	m_filterMethod = png_get_filter_type(png_ptr, info_ptr);
	assert(m_filterMethod == PNG_FILTER_TYPE_BASE);

	m_compressionType = png_get_compression_type(png_ptr, info_ptr);
	assert(m_compressionType == PNG_COMPRESSION_TYPE_BASE);

	m_interlaceType = png_get_interlace_type(png_ptr, info_ptr);
	assert(m_interlaceType == PNG_INTERLACE_NONE || m_interlaceType == PNG_INTERLACE_ADAM7);

	m_rowbytes = png_get_rowbytes(png_ptr, info_ptr);

	const uint8_t* signature = png_get_signature(png_ptr, info_ptr);
	assert(signature != nullptr);

	int num_palette = 0;
	png_colorp palette = nullptr;
	png_get_PLTE(png_ptr, info_ptr, &palette, &num_palette);

	if (true)
	{
		std::cout << "Width : " << mWidth << std::endl;
		std::cout << "Height: " << mHeight << std::endl;
		std::cout << "BitDepth : " << mBitDepth << std::endl;
		std::cout << "Channels : " << mChannels << std::endl;
		std::cout << "ColorType : " << PNG::GetColorTypeName(m_colorType) << std::endl;
		std::cout << "Filter Method : " << static_cast<uint32_t>(m_filterMethod) << std::endl;
		std::cout << "Compression Type : " << static_cast<uint32_t>(m_compressionType) << std::endl;
		std::cout << "Interlace Type : " << static_cast<uint32_t>(m_interlaceType) << std::endl;
		std::cout << "Row Bytes : " << m_rowbytes << std::endl;
	}

	mSize = mWidth * m_rowbytes;
}

void PNG::ReadData(png_structp png_ptr, png_infop info_ptr)
{
	assert(mWidth * mBitDepth / 8 * mChannels == m_rowbytes);

	png_bytep* row_pointers = png_get_rows(png_ptr, info_ptr);
	size_t size = mWidth * m_rowbytes;
	std::cout << "Buffer Size : " << size << std::endl;
	uint8_t* data = Allocate(size);
	for (uint32_t height = 0; height < mHeight; ++height)
	{
		uint8_t* dst_ptr = data + height * m_rowbytes;
		png_bytep src_ptr = *(row_pointers + height);
		std::memcpy(dst_ptr, src_ptr, m_rowbytes);
	}
}

bool PNG::Save(const char* file)
{
	assert(file != nullptr);
	FILE* fp = fopen(file, "wb");
	if (fp != nullptr)
	{
		bool flag = WriteFile(fp);
		fclose(fp);
		return flag;
	}
	return false;
}

bool PNG::WriteFile(FILE* file)
{
	png_structp png_ptr;
	png_infop info_ptr;
	bool flag = InitWriter(png_ptr, info_ptr);
	if (flag == true)
	{
		png_init_io(png_ptr, file);
		SetInfo(png_ptr, info_ptr);
		WriteData(png_ptr, info_ptr);
		png_destroy_write_struct(&png_ptr, &info_ptr);
		return flag;
	}
	return false;
}

bool PNG::InitWriter(png_structp& png_ptr, png_infop& info_ptr)
{
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, &PngError, &PngWarning);
	if (png_ptr == nullptr)
	{
		return false;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL)
	{
		png_destroy_write_struct(&png_ptr, NULL);
		return false;
	}

	if (setjmp(png_jmpbuf(png_ptr)))
	{
		png_destroy_write_struct(&png_ptr, &info_ptr);
		return false;
	}
	return true;
}

void PNG::SetInfo(png_structp png_ptr, png_infop info_ptr)
{
	png_set_IHDR(png_ptr, info_ptr, mWidth, mHeight, mBitDepth, m_colorType,
			PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	size_t palette_size = PNG_MAX_PALETTE_LENGTH * sizeof(png_color);
	png_colorp palette = static_cast<png_colorp>(png_malloc(png_ptr, palette_size));
	assert(palette != nullptr);
	std::memset(palette, 0, palette_size);
	png_set_PLTE(png_ptr, info_ptr, palette, PNG_MAX_PALETTE_LENGTH);

	png_write_info(png_ptr, info_ptr);
	png_free(png_ptr, palette);
}

void PNG::WriteData(png_structp png_ptr, png_infop info_ptr)
{
	png_set_packing(png_ptr);
	std::vector<png_bytep> row_pointers;
	row_pointers.reserve(mHeight);
	uint8_t* data = const_cast<png_bytep>(GetData());
	for (uint32_t height = 0; height < mHeight; ++height)
	{
		png_bytep src_ptr = data + height * m_rowbytes;
		row_pointers.push_back(src_ptr);
	}
	png_write_image(png_ptr, row_pointers.data());
	png_write_end(png_ptr, nullptr);
}

const char* PNG::GetColorTypeName(uint8_t type)
{
	switch(type)
	{
	case PNG_COLOR_TYPE_GRAY:
		return "PNG_COLOR_TYPE_GRAY";
		break;
	case PNG_COLOR_TYPE_GRAY_ALPHA:
		return "PNG_COLOR_TYPE_GRAY_ALPHA";
		break;
	case PNG_COLOR_TYPE_PALETTE:
		return "PNG_COLOR_TYPE_PALETTE";
		break;
	case PNG_COLOR_TYPE_RGB:
		return "PNG_COLOR_TYPE_RGB";
		break;
	case PNG_COLOR_TYPE_RGB_ALPHA:
		return "PNG_COLOR_TYPE_RGB_ALPHA";
		break;
	default:
		return "PNG_COLOR_TYPE_UNKNOWN";
		break;
	}
	return "PNG_COLOR_TYPE_UNKNOWN";
}

} /* namespace Plugin */
