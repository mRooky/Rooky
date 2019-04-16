/*
 * KernelTimer.cpp
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#include "KernelTimer.h"
#include <limits>

namespace Kernel
{

Timer::Timer(void)
{
	m_time = std::clock();
}

Timer::~Timer(void)
{
}

void Timer::Restart(void)
{
	m_time = std::clock();
}

double Timer::Elapsed(void) const
{
	double elapsed = static_cast<double>(std::clock() - m_time);
	return elapsed / static_cast<double>(CLOCKS_PER_SEC);
}

double Timer::Max(void)
{
	long limit = std::numeric_limits<std::clock_t>::max();
	return static_cast<double>(limit) / static_cast<double>(CLOCKS_PER_SEC);
}

double Timer::Min(void)
{
	return static_cast<double>(1) / static_cast<double>(CLOCKS_PER_SEC);
}

} /* namespace Kernel */
