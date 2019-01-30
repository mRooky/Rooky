/*
 * VKIndex.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKINDEX_H_
#define SOURCE_RENDER_VK_VKINDEX_H_

#include "RenderIndex.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Index : public Render::Index
{
public:
	explicit Index(Context* context);
	virtual ~Index(void) override;

public:
	virtual void Initialize(Render::Index::Type type, size_t count) override;

public:
	inline VkIndexType GetTypeVK(void) const { return mVKType; }

public:
	static VkIndexType ConvertType(const Render::Index::Type& type);
	static Render::Index::Type ConvertType(const VkIndexType& type);

protected:
	VkIndexType mVKType = VK_INDEX_TYPE_UINT16;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKINDEX_H_ */
