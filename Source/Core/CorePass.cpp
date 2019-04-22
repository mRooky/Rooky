/*
 * CorePass.cpp
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIRenderPass.h"
#include "CorePass.h"
#include "CorePath.h"
#include "CoreSystem.h"

#include <cassert>

namespace Core
{

Pass::Pass(Path* parent):
		mParent(parent)
{
}

Pass::~Pass(void)
{
	mTextures.clear();
	mParent = nullptr;
	delete mRenderPass;
	mRenderPass = nullptr;
}

void Pass::CreateRenderPass(const std::vector<GHI::Format>& formats)
{
	auto system = mParent->GetSystem();
	auto device = system->GetDevice();
	mRenderPass = device->GetFactory()->CreateRenderPass();
	for (auto format : formats)
	{
		mRenderPass->AppendFormat(format);
	}
	mRenderPass->Create();
}

} /* namespace Core */
