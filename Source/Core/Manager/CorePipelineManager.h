/*
 * CorePipelineManager.h
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREPIPELINEMANAGER_H_
#define SOURCE_CORE_MANAGER_COREPIPELINEMANAGER_H_

#include "CoreObject.h"

#include "RenderClasses.h"

#include <vector>

namespace Core
{

class PipelineManager: public Object
{
public:
	explicit PipelineManager(System* system);
	virtual ~PipelineManager(void) override;

public:
	Render::Pipeline* CreatePipeline(void);

protected:
	std::vector<Render::Pipeline*> mPipelines;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREPIPELINEMANAGER_H_ */
