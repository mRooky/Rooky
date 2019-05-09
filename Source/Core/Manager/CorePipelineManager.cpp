/*
 * CorePipelineManager.cpp
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#include "GHIDevice.h"
#include "GHIFactory.h"
#include "GHIPipeline.h"
#include "GHIPipelineLayout.h"
#include "GHIPipelineState.h"
#include "GHIShader.h"

#include "KernelFileUtility.h"

#include "CorePipelineManager.h"
#include "CoreSystem.h"

#include "UtilityRelease.h"

#include <string>
#include <iostream>

namespace Core
{

PipelineManager::PipelineManager(System* system):
		Interface(system)
{
}

PipelineManager::~PipelineManager(void)
{
	size_t count = 0;
	std::cout << "Release Shader ..." << std::endl;
	count = mShaders.size();
	Utility::Release(mShaders);
	std::cout << count << " Shader(s) Released !" << std::endl;

	std::cout << "Release Pipeline ..." << std::endl;
	count = mPipelines.size();
	Utility::Release(mPipelines);
	std::cout << count << " Pipeline(s) Released !" << std::endl;

	std::cout << "Release PipelineState ..." << std::endl;
	count = mPipelineStates.size();
	Utility::Release(mPipelineStates);
	std::cout << count << " PipelineState(s) Released !" << std::endl;

	std::cout << "Release PipelineLayout ..." << std::endl;
	count = mPipelineLayouts.size();
	Utility::Release(mPipelineLayouts);
	std::cout << count << " PipelineLayout(s) Released !" << std::endl;
}

GHI::Shader* PipelineManager::GetShader(const char* file)
{
	std::string shader_file = file;
	auto current_name = Kernel::GetFileName(shader_file);
	for (auto shader : mShaders)
	{
		auto shader_name = shader->GetName();
		bool result = (current_name == shader_name);
		if (true == result)
		{
			return shader;
		}
	}
	GHI::Shader* shader = CreateShader();
	shader->Create(file);
	return shader;
}

GHI::Pipeline* PipelineManager::GetPipeline(GHI::PipelineState* state)
{
	for (auto pipeline : mPipelines)
	{
		auto curr = pipeline->GetState();
		if (curr == state)
		{
			return pipeline;
		}
	}
	GHI::Pipeline* pipeline = CreatePipeline();
	pipeline->Create(state);
	return pipeline;
}

GHI::Shader* PipelineManager::CreateShader(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	GHI::Shader* shader = factory->CreateShader();
	mShaders.push_back(shader);
	return shader;
}

GHI::Pipeline* PipelineManager::CreatePipeline(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	GHI::Pipeline* pipeline = factory->CreatePipeline();
	mPipelines.push_back(pipeline);
	return pipeline;
}

GHI::PipelineState* PipelineManager::CreatePipelineState(void)
{
	GHI::PipelineState* state = new GHI::PipelineState;
	mPipelineStates.push_back(state);
	return state;
}

GHI::PipelineLayout* PipelineManager::CreatePipelineLayout(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	GHI::PipelineLayout* layout = factory->CreatePipelineLayout();
	mPipelineLayouts.push_back(layout);
	return layout;
}

} /* namespace Core */
