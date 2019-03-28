/*
 * CorePipelineManager.cpp
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#include "CorePipelineManager.h"
#include "CoreSystem.h"

#include "RenderDevice.h"
#include "RenderFactory.h"
#include "RenderPipeline.h"

#include "UtilRelease.h"

namespace Core
{

PipelineManager::PipelineManager(System* system):
		Object(system)
{
}

PipelineManager::~PipelineManager(void)
{
	Util::Release(mPipelines);
}

Render::Pipeline* PipelineManager::CreatePipeline(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	Render::Pipeline* pipeline = factory->CreatePipeline();
	mPipelines.push_back(pipeline);
	return pipeline;
}

} /* namespace Core */
