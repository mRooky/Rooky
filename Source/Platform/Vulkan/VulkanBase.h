/*
 * Base.h
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#ifndef BASE_H_
#define BASE_H_

#include "VulkanExport.h"
#include <string>

namespace Vulkan
{

class ROOKY_EXPORT Base
{
protected:
	Base(void);
	virtual ~Base(void);

public:
	virtual void Destroy(void);

public:
	std::string GetClassName(void) const;

private:
	Base(const Base& other) = delete;
	Base& operator=(const Base& other) = delete;
};

} /* namespace Vulkan */

#endif /* BASE_H_ */
