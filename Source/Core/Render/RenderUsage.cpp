/*
 * RenderUsage.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "RenderUsage.h"

namespace Render
{

ResourceUsage ResourceUsage::GetImageUsage(bool access)
{
	Render::ResourceUsage resource_usage = {};
	resource_usage.type = ResourceType::RESOURCE_TYPE_IMAGE;
	resource_usage.allocate.CPUAccess = access ? 1 : 0;
	return resource_usage;
}

ResourceUsage ResourceUsage::GetBufferUsage(bool access)
{
	Render::ResourceUsage resource_usage = {};
	resource_usage.type = ResourceType::RESOURCE_TYPE_BUFFER;
	resource_usage.allocate.CPUAccess = access ? 1 : 0;
	return resource_usage;
}

}
