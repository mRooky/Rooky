/*
 * KernelTimer.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELTIMER_H_
#define SOURCE_CORE_KERNEL_KERNELTIMER_H_

#include <ctime>

namespace Kernel
{

class Timer
{
public:
	Timer(void);
	~Timer(void);

public:
	void Restart(void);
	double Elapsed(void) const;

public:
	static double MaxValue(void);
	static double MinValue(void);

private:
	std::clock_t m_time = 0;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELTIMER_H_ */
