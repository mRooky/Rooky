/*
 * CoreStream.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESTREAM_H_
#define SOURCE_CORE_CORESTREAM_H_

#include "PluginStreamType.h"
#include "PluginStreamData.h"

#include <vector>

namespace Plugin
{

class StreamData;
class Stream
{
public:
	Stream(void);
	~Stream(void);

public:
	inline StreamData* GetStreamData(void) { return &mStreamData; }

protected:
	StreamData mStreamData = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESTREAM_H_ */
