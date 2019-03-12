/*
 * CoreTexture.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETEXTURE_H_
#define SOURCE_CORE_CORETEXTURE_H_

#include "CoreTarget.h"

namespace Core
{

class Texture : public Target
{
public:
	explicit Texture(System* system);
	virtual ~Texture(void) override;

public:
	void Create(const char* file);

public:
	inline Render::Sampler* GetSampler(void) const { return mSampler; }

protected:
	Render::Sampler* mSampler = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETEXTURE_H_ */
