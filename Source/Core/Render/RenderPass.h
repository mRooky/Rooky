/*
 * RenderPass.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPASS_H_
#define SOURCE_CORE_RENDER_RENDERPASS_H_

#include "RenderObject.h"
#include <vector>

namespace Render
{
class FrameBuffer;
class Pass: public Object
{
public:
	explicit Pass(Context* context);
	virtual ~Pass(void) override;

public:
	inline FrameBuffer* GetFrameBuffer(size_t index) const { return mFrameBuffers.at(index); }

protected:
	std::vector<FrameBuffer*> mFrameBuffers;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPASS_H_ */
