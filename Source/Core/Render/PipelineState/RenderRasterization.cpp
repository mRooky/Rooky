/*
 * RenderRasterization.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: rookyma
 */

#include <PipelineState/RenderRasterization.h>
#include "RenderFloat.hpp"

namespace Render
{

bool Rasterization::operator==(const Rasterization& other) const
{
		bool equal = cullMode == other.cullMode
				&& frontFace == other.frontFace
				&& polygonMode == other.polygonMode
				&& depthBiasEnable == other.depthBiasEnable
				&& depthClampEnable == other.depthClampEnable
				&& rasterizerDiscardEnable == other.rasterizerDiscardEnable;
		if (true == equal)
		{
			return CloseEnough(depthBiasConstantFactor, other.depthBiasConstantFactor)
					&& CloseEnough(depthBiasClamp, other.depthBiasClamp)
					&& CloseEnough(depthBiasSlopeFactor, other.depthBiasSlopeFactor)
					&& CloseEnough(lineWidth, other.lineWidth);
		}
		return false;
}

}
