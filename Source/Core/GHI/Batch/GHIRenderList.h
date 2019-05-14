/*
 * GHIRenderList.h
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_BATCH_GHIRENDERLIST_H_
#define SOURCE_CORE_GHI_BATCH_GHIRENDERLIST_H_

#include "GHIRenderItem.h"
#include <vector>
#include <cstdint>

namespace GHI
{

enum class RenderListType : uint32_t
{
	ZPREPASS,
	FORWARD,
	MAX_COUNT,
	UNKNOWN = ~0U
};

static inline uint32_t RenderListIndex(RenderListType type) { return static_cast<uint32_t>(type); }

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
	inline Pipeline* GetPipeline(void) const { return mPipeline; }
	inline void SetPipeline(Pipeline* pipeline) { mPipeline = pipeline; }

public:
	inline void ClearItem(void) { mRenderItems.clear(); }
	inline size_t GetItemCount(void) const { return mRenderItems.size(); }
	inline const RenderItem& GetItem(size_t index) const { return mRenderItems.at(index); }

protected:
	Pipeline* mPipeline = nullptr;
	std::vector<RenderItem> mRenderItems;
	RenderListType mType = RenderListType::UNKNOWN;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERLIST_H_ */
