/*
 * RenderIndex.h
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERINDEX_H_
#define SOURCE_CORE_RENDER_RENDERINDEX_H_

#include "RenderBuffer.h"
#include <cstdint>

namespace Render
{
class Index: public Buffer
{
public:
	enum class Type : uint32_t
	{
		UINT16,
		UINT32,
		UNKNOWN = ~0u
	};

public:
	explicit Index(Context* context);
	virtual ~Index(void) override;

public:
	inline Type GetType(void) const { return mType; }

protected:
	Type mType = Type::UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERINDEX_H_ */
