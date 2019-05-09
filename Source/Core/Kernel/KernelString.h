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

typedef std::string String;

class HashString : public HashObject
{
public:
	HashString(void) = default;
	virtual ~HashString(void) override = default;

public:
	HashString(const char* chars) { Set(chars); }
	HashString(const HashString& other) { Set(other); }
	HashString(const std::string& string) { Set(string); }

public:
	inline operator const char*(void) const { return mString.c_str(); }

public:
	inline HashString& operator=(const char* chars)
	{
		Set(chars);
		return *this;
	}

	inline HashString& operator=(const HashString& other)
	{
		Set(other);
		return *this;
	}

	inline HashString& operator=(const std::string& string)
	{
		Set(string);
		return *this;
	}

public:
	inline bool operator==(const HashString& other) const
	{
		return (mHash == other.mHash) ? (mString == other.mString) : false;
	}

public:
	inline void Set(const char* chars)
	{
		mString = chars;
		CalcHash();
	}

	inline void Set(const HashString& other)
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
	inline void CalcHash(void)
	{
		if (mString != "")
		{
			mHash.CalcHash(mString);
		}
		else
		{
			mHash = 0;
		}
	}

protected:
	std::string mString = "";
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELSTRING_H_ */
