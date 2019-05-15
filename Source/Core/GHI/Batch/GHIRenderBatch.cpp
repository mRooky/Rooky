/*
 * GHIRenderBatch.cpp
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#include "GHIRenderBatch.h"
#include "GHICommandList.h"
#include <cassert>

namespace GHI
{

RenderBatch::RenderBatch(void)
{
}

RenderBatch::~RenderBatch(void)
{
}

void RenderBatch::Render(CommandList* command)
{
	for (auto& list : mRenderLists)
	{
		list.Render(command);
	}
}

RenderList* RenderBatch::GetList(Pipeline* pipeline)
{
	RenderList* list = Search(pipeline);
	if (list == nullptr)
	{
		mRenderLists.push_back(RenderList(pipeline));
		list = &mRenderLists.back();
	}
	return list;
}

RenderList* RenderBatch::Search(Pipeline* pipeline)
{
	for (auto& list : mRenderLists)
	{
		if (list.GetPipeline() == pipeline)
		{
			return &list;
		}
	}
	return nullptr;
}

} /* namespace GHI */
