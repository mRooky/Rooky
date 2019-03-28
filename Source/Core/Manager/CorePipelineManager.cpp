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
#include "RenderShader.h"
#include "RenderPipeline.h"
#include "RenderPipelineState.h"

#include "UtilRelease.h"
#include "UtilString.h"

#include <string>
#include <iostream>

namespace Core
{

PipelineManager::PipelineManager(System* system):
		Object(system)
{
}

PipelineManager::~PipelineManager(void)
{
	size_t count = 0;
	std::cout << "Release Shader ..." << std::endl;
	count = mShaders.size();
	Util::Release(mShaders);
	std::cout << count << " Shader(s) Released !" << std::endl;

	std::cout << "Release Pipeline ..." << std::endl;
	count = mPipelines.size();
	Util::Release(mPipelines);
	std::cout << count << " Pipeline(s) Released !" << std::endl;

	std::cout << "Release PipelineState ..." << std::endl;
	count = mPipelineStates.size();
	Util::Release(mPipelineStates);
	std::cout << count << " PipelineState(s) Released !" << std::endl;
}

Render::Shader* PipelineManager::GetShader(const char* file)
{
	std::string shader_file = file;
	auto current_name = Util::GetFileName(shader_file);
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
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	Render::PipelineState* state = factory->CreatePipelineState();
	mPipelineStates.push_back(state);
	return state;
}

} /* namespace Core */
