/*
 * GHIRenderList.cpp
 *
 *  Created on: May 15, 2019
 *      Author: rookyma
 */


#include "GHIRenderList.h"
#include "GHICommandList.h"
#include <cassert>

namespace GHI
{

void RenderList::Render(CommandList* command)
{
	command->SetPipeline(mPipeline);
	for (auto& Item : mRenderItems)
	{
		Item.Render(command);
	}
}

}
