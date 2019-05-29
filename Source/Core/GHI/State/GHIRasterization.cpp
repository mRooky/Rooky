/*
 * RenderRasterization.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: rookyma
 */

#include "../../Number/NumberFloat.h"
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
			return Number::CloseEnough(depthBiasConstantFactor, other.depthBiasConstantFactor)
					&& Number::CloseEnough(depthBiasClamp, other.depthBiasClamp)
					&& Number::CloseEnough(depthBiasSlopeFactor, other.depthBiasSlopeFactor)
					&& Number::CloseEnough(lineWidth, other.lineWidth);
		}
		return false;
}

}
