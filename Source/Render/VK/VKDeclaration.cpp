/*
 * VKDeclaration.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "VKDeclaration.h"
#include "VKContext.h"
#include "VKFormat.h"

#include "VulkanFormat.h"

#include <cassert>

namespace VK
{

Declaration::Declaration(Context* context):
		Render::Declaration(context)
{
}

Declaration::~Declaration(void)
{
}

uint32_t Declaration::GetStride(void) const
{
	uint32_t stride = 0;
	const uint32_t count = mFormats.size();
	assert(count > 0);
	for (uint32_t index = 0; index < count; ++index)
	{
		auto format = mFormats.at(index);
		VkFormat vk_format = ConvertFormat(format);
		stride += Vulkan::Format::GetFormatSize(vk_format);
	}
	return stride;
}

std::vector<VkVertexInputAttributeDescription> Declaration::GetInputAttributeDescription(uint32_t binding) const
{
	std::vector<VkVertexInputAttributeDescription> input_attribute_descriptions;
	input_attribute_descriptions.reserve(mFormats.size());

	uint32_t offset = 0;
	const uint32_t count = mFormats.size();
	assert(count > 0);
	VkVertexInputAttributeDescription description = {};
	for (uint32_t index = 0; index < count; ++index)
	{
		auto format = mFormats.at(index);
		VkFormat vk_format = ConvertFormat(format);
		description.binding = binding;
		description.location = index;
		description.format = vk_format;
		description.offset = offset;
		input_attribute_descriptions.push_back(description);
		offset += Vulkan::Format::GetFormatSize(vk_format);
	}
	return input_attribute_descriptions;
}

} /* namespace VK */
