/*
 * CorePass.cpp
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#include "CoreSubPath.h"
#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIRenderPass.h"
#include "CorePath.h"
#include "CoreSystem.h"

#include <cassert>

namespace Core
{

SubPath::SubPath(Path* parent):
		mParent(parent)
{
}

SubPath::~SubPath(void)
{
	mTextures.clear();
	mParent = nullptr;
	delete mRenderPass;
	mRenderPass = nullptr;
}

void SubPath::CreateRenderPass(const std::vector<GHI::Format>& formats)
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
