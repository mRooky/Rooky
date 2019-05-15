/*
 * NumberDouble.h
 *
 *  Created on: May 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_NUMBER_NUMBERDOUBLE_H_
#define SOURCE_CORE_NUMBER_NUMBERDOUBLE_H_

#include "NumberComponent.h"

namespace Number
{

class Double
{
public:
	Double(double value = 0.0) : m_doubleValue(value) {}
	Double(const Double& other) : m_doubleValue(other.m_doubleValue) {}
	~Double(void) = default;

public:
	inline operator double (void) const { return m_doubleValue; }

public:
	inline Double& operator=(double value)
	{
		m_doubleValue = value;
		return *this;
	}

	inline Double& operator=(const Double& other)
	{
		m_doubleValue = other.m_doubleValue;
		return *this;
	}

public:
	inline bool operator==(const double& value) const
	{
		return CloseEnough(m_doubleValue, value);
	}

	inline bool operator==(const Double& other) const
	{
		return CloseEnough(m_doubleValue, other.m_doubleValue);
	}

public:
	inline const Float64Components& GetComponets(void) const { return m_components; }

private:
	union
	{
		Float64Components m_components;
		double m_doubleValue = 0.0;
	};

};

} /* namespace Number */

#endif /* SOURCE_CORE_NUMBER_NUMBERDOUBLE_H_ */
