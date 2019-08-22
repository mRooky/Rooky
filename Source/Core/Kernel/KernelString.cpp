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

