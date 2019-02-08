/*
 * CoreVertex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVERTEX_H_
#define SOURCE_CORE_COREVERTEX_H_

#include "CoreBuffer.h"

namespace Core
{

class Vertex : public Buffer
{
public:
	Vertex(void);
	virtual ~Vertex(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVERTEX_H_ */
