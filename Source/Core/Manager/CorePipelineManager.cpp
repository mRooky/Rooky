/*
 * CorePipelineManager.cpp
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#include "UtilityRelease.h"
#include "UtilityString.h"
#include "CorePipelineManager.h"
#include "CoreSystem.h"

#include "RenderDevice.h"
#include "RenderFactory.h"
#include "RenderShader.h"
#include "RenderPipeline.h"
#include "RenderPipelineState.h"
#include "RenderPipelineLayout.h"

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

Render::Shader* PipelineManager::GetShader(const char* file)
{
	std::string shader_file = file;
	auto current_name = Utility::GetFileName(shader_file);
	for (auto shader : mShaders)
	{
		auto shader_name = shader->GetName();
		bool result = (current_name == shader_name);
		if (true == result)
		{
			return shader;
		}
	}
	Render::Shader* shader = CreateShader();
	shader->Create(file);
	return shader;
}

Render::Pipeline* PipelineManager::GetPipeline(Render::PipelineState* state)
{
	for (auto pipeline : mPipelines)
	{
		auto curr = pipeline->GetState();
		if (curr == state)
		{
			return pipeline;
		}
	}
	Render::Pipeline* pipeline = CreatePipeline();
	pipeline->Create(state);
	return pipeline;
}

Render::Shader* PipelineManager::CreateShader(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	Render::Shader* shader = factory->CreateShader();
	mShaders.push_back(shader);
	return shader;
}

Render::Pipeline* PipelineManager::CreatePipeline(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	Render::Pipeline* pipeline = factory->CreatePipeline();
	mPipelines.push_back(pipeline);
	return pipeline;
}

Render::PipelineState* PipelineManager::CreatePipelineState(void)
{
	Render::PipelineState* state = new Render::PipelineState;
	mPipelineStates.push_back(state);
	return state;
}

Render::PipelineLayout* PipelineManager::CreatePipelineLayout(void)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	Render::PipelineLayout* layout = factory->CreatePipelineLayout();
	mPipelineLayouts.push_back(layout);
	return layout;
}

} /* namespace Core */
