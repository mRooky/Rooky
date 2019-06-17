/*
 * =====================================================================================
 *
 *       Filename:  GLTFPipeline.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_PIPELINE_H
#define SOURCE_GLTF_PIPELINE_H

#include "GLTFTypes.h"

namespace GLTF
{

enum class PipelineType : uint32_t
{
	SKY_BOX,
	COMMON,
	ALPHA_BLEND,
	UNKNOWN = ~0u
};

class Pipeline
{
public:
	Pipeline(void);
	~Pipeline(void);

public:
	inline PipelineType GetType(void) const { return mType; }

public:
	PipelineType mType = PipelineType::COMMON;

};

}

#endif
