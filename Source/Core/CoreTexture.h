/*
 * CoreTexture.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETEXTURE_H_
#define SOURCE_CORE_CORETEXTURE_H_

#include "CoreTarget.h"
#include <string>

namespace Core
{
class Texture : public Target
{
public:
	explicit Texture(TextureManager* manager);
	virtual ~Texture(void) override;

public:
	void Update(uint32_t index, uint32_t mipmap, const void* src);

public:
	inline void SetName(const char* name) { mName = name; }
	inline const char* GetName(void) const { return mName.c_str(); }

public:
	inline Render::Sampler* GetSampler(void) const { return mSampler; }
	inline void SetSampler(Render::Sampler* sampler) { mSampler = sampler; }

protected:
	std::string mName;
	Render::Sampler* mSampler = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETEXTURE_H_ */
