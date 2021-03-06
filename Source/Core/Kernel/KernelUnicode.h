/*
 * =====================================================================================
 *
 *       Filename:  KernelUnicode.h
 *
 * =====================================================================================
 */
#ifndef SOURCE_CORE_KERNEL_UNICODE_H
#define SOURCE_CORE_KERNEL_UNICODE_H

#include "KernelString.h"

namespace Kernel
{

class UString
{
public:
	UString(void) = default;
	~UString(void) = default;

private:
	std::u32string m_string;
};
//typedef std::u32string UString;

}

#endif
