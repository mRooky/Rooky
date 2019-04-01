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
	Render::Shader* GetShader(const char* file);

public:
	Render::Shader* CreateShader(void);
	Render::Pipeline* CreatePipeline(void);
	Render::PipelineState* CreatePipelineState(void);
	Render::PipelineLayout* CreatePipelineLayout(void);

protected:
	std::vector<Render::Shader*> mShaders;
	std::vector<Render::Pipeline*> mPipelines;
	std::vector<Render::PipelineState*> mPipelineStates;
	std::vector<Render::PipelineLayout*> mPipelineLayouts;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREPIPELINEMANAGER_H_ */
