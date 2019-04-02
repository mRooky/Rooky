/*
 * UtilData.h
 *
 *  Created on: Jan 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_UTILITY_UTILITYBYTEBUFFER_H_
#define SOURCE_CORE_UTILITY_UTILITYBYTEBUFFER_H_

#include <cstdint>
#include <cstddef>

namespace Utility
{

class ByteBuffer
{
public:
	ByteBuffer(void);
	~ByteBuffer(void);

public:
	uint8_t* Allocate(size_t size);

public:
	void Clear(void);
	void Move(ByteBuffer& other);
	void Copy(const ByteBuffer& other);

public:
	inline size_t Size(void) const { return m_size; }
	inline uint8_t* Bytes(void) const { return m_bytes; }

private:
	size_t m_size = 0;
	uint8_t* m_bytes = nullptr;

};

} /* namespace Util */

#endif /* SOURCE_CORE_UTILITY_UTILITYBYTEBUFFER_H_ */
