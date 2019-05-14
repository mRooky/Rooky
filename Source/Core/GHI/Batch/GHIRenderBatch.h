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

class RenderBatch
{
	static const size_t MAX_LIST_COUNT = static_cast<size_t>(RenderListType::MAX_COUNT);
public:
	RenderBatch(void);
	~RenderBatch(void);

public:
	RenderList* GetList(RenderListType type)
	{
		uint32_t index = RenderListIndex(type);
		return &mRenderLists.GetElementAt(index);
	}

protected:
	Kernel::FixedVector<RenderList, MAX_LIST_COUNT> mRenderLists;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERBATCH_H_ */
