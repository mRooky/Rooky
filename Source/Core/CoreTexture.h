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
	void Create(const char* file, const Render::ImageLayout& layout);

public:
	inline const char* GetName(void) const { return mName.c_str(); }
	inline Render::Sampler* GetSampler(void) const { return mSampler; }

protected:
	std::string mName;
	Render::Sampler* mSampler = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETEXTURE_H_ */
