/*
 * RenderRasterization.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: rookyma
 */

#include "MathFloat.hpp"
#include "GHIRasterization.h"

namespace GHI
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
			return Math::CloseEnough(depthBiasConstantFactor, other.depthBiasConstantFactor)
					&& Math::CloseEnough(depthBiasClamp, other.depthBiasClamp)
					&& Math::CloseEnough(depthBiasSlopeFactor, other.depthBiasSlopeFactor)
					&& Math::CloseEnough(lineWidth, other.lineWidth);
		}
		return false;
}

}
