/*
 * RenderUsage.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "RenderUsage.h"

namespace Render
{

ResourceUsage GetImageUsage(bool access)
{
	Render::ResourceUsage resource_usage = {};
	resource_usage.heap.Image = 1;
	resource_usage.heap.CPUAccess = access ? 1 : 0;
	return resource_usage;
}

ResourceUsage GetBufferUsage(bool access)
{
	Render::ResourceUsage resource_usage = {};
	resource_usage.heap.Buffer = 1;
	resource_usage.heap.CPUAccess = access ? 1 : 0;
	return resource_usage;
}

}
