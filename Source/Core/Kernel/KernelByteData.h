/*
 * KernelByteData.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELBYTEDATA_H_
#define SOURCE_CORE_KERNEL_KERNELBYTEDATA_H_

#include "KernelAlignment.h"
#include <cstdint>

namespace Kernel
{

class ByteData
{
public:
	ByteData(void);
	~ByteData(void);

public:
	uint8_t* Allocate(size_t size);

public:
	void Clear(void);
	void Move(ByteData& other);
	void Copy(const ByteData& other);

public:
	inline size_t Size(void) const { return m_size; }
	inline uint8_t* Bytes(void) const { return m_bytes; }

private:
	size_t m_size = 0;
	uint8_t* m_bytes = nullptr;
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELBYTEDATA_H_ */
