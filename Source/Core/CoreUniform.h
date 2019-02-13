/*
 * CoreUniform.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREUNIFORM_H_
#define SOURCE_CORE_COREUNIFORM_H_

#include "CoreBuffer.h"

namespace Core
{

class Uniform: public Buffer
{
public:
	explicit Uniform(BufferManager* creator);
	virtual ~Uniform(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREUNIFORM_H_ */
