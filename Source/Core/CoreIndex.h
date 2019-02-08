/*
 * CoreIndex.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREINDEX_H_
#define SOURCE_CORE_COREINDEX_H_

#include "CoreBuffer.h"

namespace Core
{

class Index : public Buffer
{
private:
	Index(void);
	virtual ~Index(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREINDEX_H_ */
