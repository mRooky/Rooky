/*
 * CorePolicy.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#include "CorePolicy.h"
#include "CoreSubPolicy.h"
#include "CoreSystem.h"
#include "CoreRenderTarget.h"
#include "UtilityRelease.h"

#include "GHIDevice.h"
#include "GHIRenderPass.h"
#include "GHICommandList.h"
#include "GHIImageLayout.h"
#include "GHIUsageType.h"
#include "GHIFactory.h"
#include "GHIImage.h"

#include <cassert>

namespace Core
{

Policy::Policy(System* system):
		Interface(system)
{
}

Policy::~Policy(void)
{
	delete mRenderPass;
	mRenderPass = nullptr;
	delete mDepthStencil;
	mDepthStencil = nullptr;
	Utility::Release(mSubPolicies);
}

void Policy::Create(void)
{
	auto device = mSystem->GetDevice();
	GHI::Factory* factory = device->GetFactory();
	mRenderPass = factory->CreateRenderPass();
	for (auto target : mRenderTargets)
	{
		const auto& layout = target->GetLayout();
		mRenderPass->AppendFormat(layout.GetFormat());
	}

	if (mDepthStencil != nullptr)
	{
		const auto& layout = mDepthStencil->GetLayout();
		mRenderPass->SetDepthStencilFormat(layout.GetFormat());
	}
	mRenderPass->Create(mSubPolicies.size());
}

void Policy::Render(GHI::CommandList* command, const std::vector<Renderable*>& renderables)
{
	assert(command->IsBegin());
	RenderSub(command, renderables);
}

void Policy::RenderSub(GHI::CommandList* command, const std::vector<Renderable*>& renderables)
{
	for(auto sub : mSubPolicies)
	{
		sub->Render(command, renderables);
	}
}

void Policy::CreateDepthStencil(GHI::Format format, const Math::Extent2Di& extent)
{
	assert(mDepthStencil == nullptr);

	GHI::ImageLayout image_layout = {};
	image_layout.SetType(GHI::ImageType::IMAGE_TYPE_2D);
	image_layout.SetExtent(extent);
	image_layout.SetFormat(format);

	GHI::UsageType image_usage = {};
	image_usage.type = GHI::ResourceType::IMAGE;
	image_usage.depthStencil = TRUE;

	mDepthStencil = new RenderTarget(*mSystem);
	mDepthStencil->Create(image_layout, image_usage);
}

RenderTarget* Policy::CreateRenderTarget(const GHI::ImageLayout& layout, const GHI::UsageType& usage)
{
	RenderTarget* target = new RenderTarget(*mSystem);
	mRenderTargets.push_back(target);
	target->Create(layout, usage);
	return target;
}

} /* namespace Core */
