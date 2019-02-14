/*
 * CorePass.cpp
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#include "CorePass.h"
#include "CorePath.h"
#include "CoreSystem.h"

#include "RenderContext.h"
#include "RenderPass.h"

#include <cassert>

namespace Core
{

Pass::Pass(Path* parent):
		mParent(parent)
{
}

Pass::~Pass(void)
{
	mParent = nullptr;
	delete mRenderPass;
	mRenderPass = nullptr;
}

void Pass::Create(const std::vector<Render::Format>& formats)
{
	auto system = mParent->GetSystem();
	auto context = system->GetContext();
	mRenderPass = context->CreatePass();
	for (auto format : formats)
	{
		mRenderPass->AppendFormat(format);
	}
	mRenderPass->Create();
}

} /* namespace Core */
