/*
 * CoreGraphicsPipeline.h
 *
 *  Created on: May 15, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREGRAPHICSPIPELINE_H_
#define SOURCE_CORE_COREGRAPHICSPIPELINE_H_

namespace Core
{

class ComputePipeline
{
	friend class Viewport;
private:
	ComputePipeline(void);
	~ComputePipeline(void);
};

class GraphicsPipeline
{
	friend class Viewport;
private:
	GraphicsPipeline(void);
	~GraphicsPipeline(void);
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREGRAPHICSPIPELINE_H_ */
