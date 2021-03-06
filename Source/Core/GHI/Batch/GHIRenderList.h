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
class Pipeline;
class RenderList
{
public:
	RenderList(Pipeline* pipeline) { SetPipeline(pipeline); }
	~RenderList(void) = default;

public:
	void Render(CommandList* command);

public:
	void AppendItem(const RenderItem& item);

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
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERLIST_H_ */
