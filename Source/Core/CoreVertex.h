/*
 * CoreVertex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVERTEX_H_
#define SOURCE_CORE_COREVERTEX_H_

#include "CoreBuffer.h"
#include <cstdint>

namespace Core
{

class Vertex : public Buffer
{
public:
	explicit Vertex(BufferManager* creator);
	virtual ~Vertex(void) override;

public:
	void Create(Render::Element* element, uint32_t count);

protected:
	uint32_t mCount = 0;
	Render::Element* mElement = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVERTEX_H_ */
