/*
 * =====================================================================================
 *
 *       Filename:  KernelString.cpp
 *
 * =====================================================================================
 */
#include "KernelString.h"
#include <cassert>
#include <functional>

namespace Kernel
{

String::String(const char* str)
{
	std::string buffer(str);
	m_data = std::wstring(buffer.begin(), buffer.end());
}


String::String(const std::string& str)
{
	m_data = std::wstring(str.begin(), str.end());
}

void String::Set(const char* str)
{
	std::string buffer(str);
	m_data = std::wstring(buffer.begin(), buffer.end());
}

size_t String::GetHash(void) const
{
	return std::hash<std::wstring>()(m_data);
}

}

