/*
 * RenderVendor.h
 *
 *  Created on: Mar 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERVENDOR_H_
#define SOURCE_CORE_RENDER_RENDERVENDOR_H_

#include <string>

namespace Render
{

class Vendor
{
public:
	Vendor(void);
	virtual ~Vendor(void);

public:
	size_t memory = 0;
	std::string vendor;
	std::string version;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERVENDOR_H_ */
