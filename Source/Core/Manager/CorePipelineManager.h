/*
 * CorePipelineManager.h
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREPIPELINEMANAGER_H_
#define SOURCE_CORE_MANAGER_COREPIPELINEMANAGER_H_

#include "GHIClasses.h"
#include "CoreInterface.h"
#include <vector>

namespace Core
{

class PipelineManager: public Interface
{
public:
	explicit PipelineManager(System* system);
	virtual ~PipelineManager(void) override;

public:
	GHI::Shader* GetShader(const char* file);
	GHI::Pipeline* GetPipeline(GHI::PipelineState* state);

public:
	GHI::Shader* CreateShader(void);
	GHI::Pipeline* CreatePipeline(void);
	GHI::PipelineState* CreatePipelineState(void);
	GHI::PipelineLayout* CreatePipelineLayout(void);

protected:
	std::vector<GHI::Shader*> mShaders;
	std::vector<GHI::Pipeline*> mPipelines;
	std::vector<GHI::PipelineState*> mPipelineStates;
	std::vector<GHI::PipelineLayout*> mPipelineLayouts;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREPIPELINEMANAGER_H_ */
