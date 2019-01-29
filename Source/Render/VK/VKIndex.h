/*
 * VKIndex.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKINDEX_H_
#define SOURCE_RENDER_VK_VKINDEX_H_

#include "VKBuffer.h"

namespace VK
{

class Index : public Buffer
{
public:
	explicit Index(Context* context);
	virtual ~Index(void) override;

public:
	inline VkIndexType GetType(void) const { return mType; }

protected:
	VkIndexType mType = VK_INDEX_TYPE_UINT16;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKINDEX_H_ */
