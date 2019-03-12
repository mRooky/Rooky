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
	resource_usage.heap.Image = 1;
	resource_usage.heap.CPUAccess = access ? 1 : 0;
	return resource_usage;
}

ResourceUsage ResourceUsage::GetBufferUsage(bool access)
{
	Render::ResourceUsage resource_usage = {};
	resource_usage.heap.Buffer = 1;
	resource_usage.heap.CPUAccess = access ? 1 : 0;
	return resource_usage;
}

static_assert(sizeof(ResourceUsage) == sizeof(uint32_t) * 2, "ResourceUsage Size : 5");

}
