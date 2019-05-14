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
	SubPass(uint8_t mask) : mAllMask(mask) {}
	~SubPass(void) = default;

public:
	inline operator uint8_t(void) const { return mAllMask; }

public:
	inline SubPass& operator=(uint8_t mask)
	{
		mAllMask = mask;
		return *this;
	}

	inline SubPass& operator=(const SubPass& other)
	{
		mAllMask = other.mAllMask;
		return *this;
	}

public:
	inline void UseAttachment(uint32_t index)
	{
		attachmentMask &= (1u << index);
	}

	inline bool IsAttachmentUsed(uint32_t index) const
	{
		return (attachmentMask & (1u << index)) ? true : false;
	}

	inline bool IsDepthStencilUsed(void) const { return depthStencil == TRUE; }

public:
	inline uint8_t GetAllMask(void) const { return mAllMask; }

protected:
	union
	{
		struct
		{
			uint8_t depthStencil	: 1;
			uint8_t attachmentMask	: 7;
		};
		uint8_t mAllMask = 0;
	};
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_GHISUBPASS_H_ */
