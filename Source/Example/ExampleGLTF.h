/*
 * ExampleGLTF.h
 *
 * Created on: Jun 3, 2019
 *     Author: rookyma
 */

#ifndef EXAMPLE_EXAMPLEGLTF_H_
#define EXAMPLE_EXAMPLEGLTF_H_

#include "ExampleBase.h"
#include "../Core/CoreTexture.h"

namespace Example
{

class GLTF : public Base
{
public:
	GLTF(void);
	virtual ~GLTF(void) override;

public:
	virtual void Initialize(void) override;
	virtual void RecordCommands(void) override;

protected:
	virtual void CreateBRDF(void);

protected:
	virtual void CreateBaseColor(const char* file);
	virtual void CreateMetallicRoughness(const char* file);
	virtual void CreateNormal(const char* file);
	virtual void CreateOcclusion(const char* file);
	virtual void CreateEmissive(const char* file);


protected:
	Core::Texture* mBaseColor = nullptr;
	Core::Texture* mMetallicRoughness = nullptr;
	Core::Texture* nNormal = nullptr;
	Core::Texture* mOcclusion = nullptr;
	Core::Texture* mEmissive = nullptr;

};

}

#endif
