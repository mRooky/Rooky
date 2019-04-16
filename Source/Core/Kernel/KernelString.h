/*
 * KernelString.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELSTRING_H_
#define SOURCE_CORE_KERNEL_KERNELSTRING_H_

#include "KernelHashObject.h"
#include <string>

namespace Kernel
{

class String : public HashObject
{
public:
	String(void) = default;
	String(const char* chars) { Set(chars); }
	String(const String& other) { Set(other); }
	String(const std::string& string) { Set(string); }

public:
	virtual ~String(void) override = default;

public:
	virtual void CalcHash(void) override
	{
		mHash = std::hash<std::string>()(mString);
	}

public:
	inline const char* Char(void) const { return mString.c_str(); }

public:
	inline String& operator=(const char* chars)
	{
		Set(chars);
		return *this;
	}

	inline String& operator=(const String& other)
	{
		Set(other);
		return *this;
	}

	inline String& operator=(const std::string& string)
	{
		Set(string);
		return *this;
	}

public:
	inline bool operator==(const String& other) const
	{
		return (mHash == other.mHash) ? (mString == other.mString) : false;
	}

public:
	inline void Set(const char* chars)
	{
		mString = chars;
		CalcHash();
	}

	inline void Set(const String& other)
	{
		mHash = other.mHash;
		mString = other.mString;
	}

	inline void Set(const std::string& string)
	{
		mString = string;
		CalcHash();
	}

protected:
	std::string mString;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELSTRING_H_ */
