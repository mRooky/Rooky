/*
 * GHIRenderBatch.h
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_BATCH_GHIRENDERBATCH_H_
#define SOURCE_CORE_GHI_BATCH_GHIRENDERBATCH_H_

#include "GHIRenderList.h"

namespace GHI
{
class Pipeline;
class RenderBatch
{
public:
	RenderBatch(void);
	~RenderBatch(void);

public:
	void Render(CommandList* command);

public:
	RenderList* GetList(Pipeline* pipeline);

public:
	inline void ClearList(void) { mRenderLists.clear(); }
	inline size_t GetListCount(void) const { return mRenderLists.size(); }
	inline const RenderList& GetList(size_t index) const { return mRenderLists.at(index); }

protected:
	RenderList* Search(Pipeline* pipeline);

protected:
	std::vector<RenderList> mRenderLists;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERBATCH_H_ */
