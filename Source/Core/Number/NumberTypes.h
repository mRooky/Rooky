/*
 * NumberComponent.h
 *
 *  Created on: May 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_NUMBER_NUMBERCOMPONENT_H_
#define SOURCE_CORE_NUMBER_NUMBERCOMPONENT_H_

#include "NumberDefine.h"

namespace Number
{

typedef struct Float16Components
{
#ifdef NUMBER_LITTLE_ENDIAN
	uint32_t mantissa :10;
	uint32_t exponent :5;
	uint32_t sign :1;
#else
	uint32_t sign :1;
	uint32_t exponent :5;
	uint32_t mantissa :10;
#endif
} Float16Components;

typedef struct Float32Components
{
#ifdef NUMBER_LITTLE_ENDIAN
	uint32_t mantissa :23;
	uint32_t exponent :8;
	uint32_t sign :1;
#else
	uint32_t sign :1;
	uint32_t exponent :8;
	uint32_t mantissa :23;
#endif
} Float32Components;

typedef struct Float64Components
{
#ifdef NUMBER_LITTLE_ENDIAN
	uint64_t mantissa :52;
	uint64_t exponent :11;
	uint64_t sign :1;
#else
	uint64_t sign :1;
	uint64_t exponent :11;
	uint64_t mantissa :52;
#endif
} Float64Components;

} /* namespace Number */

#endif /* SOURCE_CORE_NUMBER_NUMBERCOMPONENT_H_ */
