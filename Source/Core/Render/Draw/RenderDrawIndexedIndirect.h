/*
 * RenderDrawIndexedIndirect.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_DRAW_RENDERDRAWINDEXEDINDIRECT_H_
#define SOURCE_CORE_RENDER_DRAW_RENDERDRAWINDEXEDINDIRECT_H_

#include <Draw/RenderDrawIndirect.h>

namespace Render
{

class DrawIndexedIndirect: public DrawIndirect
{
public:
	DrawIndexedIndirect(void);
	virtual ~DrawIndexedIndirect(void) override;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_DRAW_RENDERDRAWINDEXEDINDIRECT_H_ */