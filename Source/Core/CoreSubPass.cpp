/*
 * CorePass.cpp
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#include "CorePass.h"
#include "CoreSubPass.h"
#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIRenderPass.h"
#include "CoreSystem.h"

#include <cassert>

namespace Core
{

SubPass::SubPass(Pass* parent):
		mParent(parent)
{
}

SubPass::~SubPass(void)
{
	mTextures.clear();
	mParent = nullptr;
	delete mRenderPass;
	mRenderPass = nullptr;
}

void SubPass::CreateRenderPass(const std::vector<GHI::Format>& formats)
{
	auto system = mParent->GetSystem();
	auto device = system->GetDevice();
	mRenderPass = device->GetFactory()->CreateRenderPass();
	for (auto format : formats)
	{
		mRenderPass->AppendFormat(format);
	}
	mRenderPass->Create(1);
}

} /* namespace Core */
