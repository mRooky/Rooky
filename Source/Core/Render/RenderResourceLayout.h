/*
 * RenderResourceLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_

#include "RenderObject.h"

namespace Render
{
class PipelineLayout;
class ResourceLayout : public Object
{
public:
	explicit ResourceLayout(Context* context);
	virtual ~ResourceLayout(void) override;

public:
	virtual PipelineLayout* UpdatePipelineLayout(void) = 0;

protected:
	bool mDirty = true;
	PipelineLayout* mCurrentLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCELAYOUT_H_ */
