/*
 * KernalGuid.cpp
 *
 *  Created on: May 10, 2019
 *      Author: rookyma
 */

#include "KernelGuid.h"
#include "KernelRandom.h"
#include <sstream>
#include <iomanip>


namespace Kernel
{

String Guid::GetString(void) const
{
	std::stringstream ss;
	ss.width(2);
	auto data = reinterpret_cast<const uint8_t*>(&mCode);
	for (size_t i = 0; i < sizeof(mCode); ++i)
	{
		ss << std::hex << std::setw(2) << std::setfill('0');
		ss << static_cast<unsigned int>(*(data + i));
		bool separator = (i == 3 || i == 5 || i == 7 || i == 9);
		if (separator)
		{
			ss << ss.widen('-');
		}
	}
	return ss.str();
}

void Guid::Generate(void)
{
	RandomBytes(&mCode, sizeof(mCode));
	mCode[0] &= 0xffffffff'ffff0fffULL;
	mCode[0] |= 0x00000000'00004000ULL;
	mCode[1] &= 0x3fffffff'ffffffffULL;
	mCode[1] |= 0x80000000'00000000ULL;
}

}
