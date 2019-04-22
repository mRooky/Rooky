/*
 * RenderDrawIndexedIndirect.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWINDEXEDINDIRECT_H_
#define SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWINDEXEDINDIRECT_H_

#include "GHIDrawIndirect.h"

namespace GHI
{

class DrawIndexedIndirect: public DrawIndirect
{
public:
	DrawIndexedIndirect(void);
	virtual ~DrawIndexedIndirect(void) override;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERDRAW_RENDERDRAWINDEXEDINDIRECT_H_ */
