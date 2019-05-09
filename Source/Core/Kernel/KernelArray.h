/*
 * KernelArray.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELARRAY_H_
#define SOURCE_CORE_KERNEL_KERNELARRAY_H_

#include "KernelUtility.h"

#include <array>

namespace Kernel
{

template<typename T, size_t N>
class Array
{
public:
	Array(void) = default;
	~Array(void) = default;

public:
	inline void Set(size_t index, const T& element)
	{
		ThrowIfOutOfRange(index);
		m_elements.at(index) = element;
	}

	inline void Append(const T& element)
	{
		ThrowIfFull();
		m_elements.at(m_count) = element;
		++m_count;
	}

	inline void Clear(void) { m_count = 0; }

public:
	inline const T& GetElementAt(size_t index) const
	{
		ThrowIfOutOfRange(index);
		return m_elements.at(index);
	}

	inline size_t GetElementCount(void) const { return m_count; }

public:
	inline constexpr size_t Capability(void) const { return N; }

private:
	inline void ThrowIfFull(void) const
	{
		if(m_count == N)
		{
			throw "Array Is Full !";
		}
	}

	inline void ThrowIfOutOfRange(size_t index) const
	{
		if(index >= m_count)
		{
			throw "Array Out Of Range !";
		}
	}

private:
	size_t m_count = 0;
	std::array<T, N> m_elements;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELARRAY_H_ */
