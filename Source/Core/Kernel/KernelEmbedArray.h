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
class EmbedArray
{
	typedef T ElementType;
public:
	EmbedArray(void) = default;
	~EmbedArray(void) = default;

public:
	inline bool FindElement(const ElementType& element) const
	{
		for (size_t index = 0; index < m_count; ++index)
		{
			const ElementType& exist = m_elements.at(index);
			if (element == exist)
			{
				return true;
			}
		}
		return false;
	}

	inline void SetElement(size_t index, const T& element)
	{
		ThrowIfOutOfRange(index);
		m_elements.at(index) = element;
	}

	inline void PushElement(const T& element)
	{
		ThrowIfFull();
		m_elements.at(m_count) = element;
		++m_count;
	}

	inline void ClearElement(void) { m_count = 0; }

public:
	inline T& GetElementAt(size_t index)
	{
		ThrowIfOutOfRange(index);
		return m_elements.at(index);
	}

	inline const T& GetElementAt(size_t index) const
	{
		ThrowIfOutOfRange(index);
		return m_elements.at(index);
	}

	inline size_t GetElementCount(void) const { return m_count; }

public:
	inline constexpr size_t Capability(void) const noexcept { return N; }

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
			throw "Index Out Of Range !";
		}
	}

private:
	size_t m_count = 0;
	std::array<ElementType, N> m_elements;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELARRAY_H_ */
