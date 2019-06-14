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

namespace Kernel
{

typedef std::string String;
typedef std::wstring WString;
/*
class String
{
public:
	String(void) {}
	~String(void) {}

public:
	String(const char* str) { m_string = str; }
	String(const std::string& str) { m_string = str; }
	String(const String& other) { m_string = other.m_string; }

public:
	inline const std::string& GetString(void) const { return m_string; }

public:
	inline operator std::string(void) { return m_string; }
	inline operator const char*(void) { return m_string.c_str(); }

public:
	inline String& operator=(const String& other)
	{
		m_string = other.m_string;
		return *this;
	}

	inline String& operator=(const std::string& str)
	{
		m_string = str;
		return *this;
	}

	inline String& operator=(const char* str)
	{
		m_string = str;
		return *this;
	}

	inline bool operator==(const String& other) const
	{
		return m_string == other.m_string;
	}

	inline bool operator==(const std::string& str) const
	{
		return m_string == str;
	}

	inline bool operator==(const char* str) const
	{
		return m_string == str;
	}

public:
	inline operator std::string&(void) { return m_string; }
	inline operator const std::string&(void) const { return m_string; }
	inline operator const char*(void) const { return m_string.c_str(); }

private:
	std::string m_string;
};
*/

}

#endif
