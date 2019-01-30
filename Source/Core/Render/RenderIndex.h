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
#include <cstddef>

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
	virtual void Initialize(Type type, size_t count) = 0;

public:
	inline size_t GetCount(void) const { return mCount; }
	inline Type GetType(void) const { return mType; }

public:
	static size_t GetTypeSize(const Type& type);

protected:
	size_t mCount = 0;
	Type mType = Type::UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERINDEX_H_ */
