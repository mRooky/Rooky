/*
 * CoreStorage.h
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTORAGE_H_
#define SOURCE_CORE_CORESTORAGE_H_

#include "CoreBuffer.h"

namespace Core
{

class Storage: public Buffer
{
public:
	explicit Storage(BufferManager* creator);
	virtual ~Storage(void) override;

public:
	void Create(size_t size);
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTORAGE_H_ */
