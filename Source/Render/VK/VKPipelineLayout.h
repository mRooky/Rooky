/*
 * VKPipelineLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINELAYOUT_H_
#define SOURCE_RENDER_VK_VKPIPELINELAYOUT_H_

#include "RenderPipelineLayout.h"

namespace VK
{

class PipelineLayout: public Render::PipelineLayout
{
public:
	PipelineLayout(void);
	virtual ~PipelineLayout(void) override;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINELAYOUT_H_ */
