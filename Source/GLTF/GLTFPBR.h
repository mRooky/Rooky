/*
 * =====================================================================================
 *
 *       Filename:  GLTFPBR.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_PBR_H
#define SOURCE_GLTF_PBR_H

#include "../Core/GHI/GHIClasses.h"
#include "../Core/GHI/GHIPipelineState.h"
#include <map>

namespace GLTF
{

class Render;
class PBR
{
public:
	PBR(Render* parent);
	~PBR(void);

public:
	GHI::Pipeline* GetOrCreatePipeline(const GHI::PipelineState& state);

protected:
	Render* mParent = nullptr;
	std::map<GHI::PipelineState, GHI::Pipeline*> mPipelines;
};

}

#endif
