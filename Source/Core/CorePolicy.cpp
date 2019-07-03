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
#include "Utility/UtilityRelease.h"

#include "GHI/GHIDevice.h"
#include "GHI/GHIRenderPass.h"
#include "GHI/GHICommandList.h"
#include "GHI/GHIImageLayout.h"
#include "GHI/GHIFactory.h"
#include "GHI/GHIImage.h"

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
	image_layout.SetType(GHI::ImageType::IT_2D);
	image_layout.SetExtent(extent);
	image_layout.SetFormat(format);

	GHI::ResourceUsage image_usage = {};
	image_usage.imageUsage.depthStencil = TRUE;

	mDepthStencil = new RenderTarget(*mSystem);
	mDepthStencil->Create(image_layout, image_usage);
}

RenderTarget* Policy::CreateRenderTarget(const GHI::ImageLayout& layout, const GHI::ResourceUsage& usage)
{
	RenderTarget* target = new RenderTarget(*mSystem);
	mRenderTargets.push_back(target);
	target->Create(layout, usage);
	return target;
}

} /* namespace Core */
