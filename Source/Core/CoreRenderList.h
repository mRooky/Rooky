/*
 * CoreRenderList.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORERENDERLIST_H_
#define SOURCE_CORE_CORERENDERLIST_H_

#include "CoreRenderItem.h"
#include <vector>
#include <cstdint>

namespace Core
{

enum class RenderListType : uint32_t
{
	ZPREPASS,
	FORWARD,
	MAX_COUNT,
	UNKNOWN = ~0U
};

class RenderList
{
public:
	RenderList(void);
	virtual ~RenderList(void);

public:
	RenderItem* CreateRenderItem(void);

public:
	inline RenderListType GetType(void) const { return mType; }

public:
	inline void ClearItem(void) { mRenderItems.clear(); }
	inline size_t GetItemCount(void) const { return mRenderItems.size(); }
	inline const RenderItem& GetItem(size_t index) const { return mRenderItems.at(index); }

protected:
	std::vector<RenderItem> mRenderItems;
	RenderListType mType = RenderListType::UNKNOWN;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORERENDERLIST_H_ */
