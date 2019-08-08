/*
 * KernalGuid.cpp
 *
 *  Created on: May 10, 2019
 *      Author: rookyma
 */

#include "KernelGuid.h"
#include <sstream>
#include <iomanip>
#include <random>

namespace Kernel
{

void Guid::Generate(void)
{
	std::random_device rd;
	std::uniform_int_distribution<uint64_t> dist(0, (uint64_t)(~0));
	mCode[0] = dist(rd);
	mCode[1] = dist(rd);
	mCode[0] &= 0xFFFFFFFFFFFF0FFFULL;
	mCode[0] |= 0x0000000000004000ULL;
	mCode[1] &= 0x3FFFFFFFFFFFFFFFULL;
	mCode[1] |= 0x8000000000000000ULL;
}

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

}
