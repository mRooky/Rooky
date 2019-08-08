/*
 * NumberUint128.h
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_NUMBER_NUMBERUINT128_H_
#define SOURCE_CORE_NUMBER_NUMBERUINT128_H_

#include <cstdint>
#include <cstddef>

namespace Number
{

class Uint128
{
public:
	Uint128(void) = default;
	~Uint128(void) = default;

public:
	Uint128(const Uint128& other)
	{
		upper = other.upper;
		lower = other.lower;
	}

public:
	inline operator uint64_t*(void)
	{
		return m_buffer;
	}

	inline operator const uint64_t*(void) const
	{
		return m_buffer;
	}

	inline uint64_t& operator[](size_t index)
	{
		return m_buffer[index];
	}

	inline const uint64_t& operator[](size_t index) const
	{
		return m_buffer[index];
	}

public:
	inline Uint128& operator=(const Uint128& other)
	{
		upper = other.upper;
		lower = other.lower;
		return *this;
	}

public:
	inline bool operator==(const Uint128& other) const
	{
		return (upper == other.upper) && (lower == other.lower);
	}

private:
	union
	{
		struct
		{
			uint64_t upper;
			uint64_t lower;
		};
		uint64_t m_buffer[2] = {};
	};
};

} /* namespace Number */

#endif /* SOURCE_CORE_NUMBER_NUMBERUINT128_H_ */
