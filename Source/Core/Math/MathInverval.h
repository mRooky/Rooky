/*
 * =====================================================================================
 *
 *       Filename:  MathInverval.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_MATH_INTERVAL_H
#define SOURCE_CORE_MATH_INTERVAL_H

#include <limits>

namespace Math
{

template<typename T>
class Interval_t
{
public:
	Interval_t(void)
	{
	}

	~Interval_t(void)
	{
	}

public:
	Interval_t(T start, T end)
	{
		Set(start, end);
	}

public:
	inline void Set(const T& start, const T& end)
	{
		this->start = start;
		this->end = end;
	}

public:
	inline T GetLength(void) const
	{
		return end - start;
	}

	inline bool IsValid(void) const
	{
		return start <= end;
	}

	inline bool IsEmpty(void) const
	{
		return start >= end;
	}

	inline bool IsInside(T value) const
	{
		return start <= value && value <= end;
	}

public:
	T start = std::numeric_limits<T>::max();
	T end = std::numeric_limits<T>::lowest();

};

}

#endif
