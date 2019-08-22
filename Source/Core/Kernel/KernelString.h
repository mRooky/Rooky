/*
 * =====================================================================================
 *
 *       Filename:  KernelString.h
 *
 * =====================================================================================
 */
#ifndef SOURCE_CORE_KERNEL_STRING_H
#define SOURCE_CORE_KERNEL_STRING_H

#include <string>
#include <cstdint>

namespace Kernel
{

class String
{
public:
	inline String(void) = default;
	inline String(const String& str):
		m_data(str.m_data)
	{}
	inline ~String(void) = default;

public:
	explicit String(const char* str)
	{
		Set(str);
	}

	explicit String(const std::string& str)
	{
		Set(str.c_str());
	}

	explicit String(const std::wstring& str) :
		m_data(str)
	{}

public:
	inline String& operator=(const char* str)
	{
		Set(str);
		return *this;
	}

	inline String& operator=(const String& str)
	{
		if (this != & str)
		{
			m_data = str.m_data;
		}
		return *this;
	}

public:
	inline operator const wchar_t* (void) const
	{
		return m_data.c_str();
	}

public:
	size_t GetHash(void) const;

private:
	void Set(const char* str);

private:
	std::wstring m_data;

};

}

#endif
