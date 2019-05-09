/*
 * GHISubPass.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_GHISUBPASS_H_
#define SOURCE_CORE_GHI_GHISUBPASS_H_

#include "GHIDefine.h"

namespace GHI
{

class SubPass
{
public:
	SubPass(void) = default;
	~SubPass(void) = default;

public:
	inline void Enabled(bool use) { enabled = use ? TRUE : FALSE; }
	inline bool IsEnabled(void) const { return enabled == TRUE; }

protected:
	union
	{
		struct
		{
			uint8_t enabled : 1;
			// index
			uint8_t mask_6	: 1;
			uint8_t mask_5	: 1;
			uint8_t mask_4	: 1;
			uint8_t mask_3	: 1;
			uint8_t mask_2	: 1;
			uint8_t mask_1	: 1;
			uint8_t mask_0	: 1;
		};
		uint8_t mAllMask = 0;
	};
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_GHISUBPASS_H_ */
