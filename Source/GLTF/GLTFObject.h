/*
 * =====================================================================================
 *
 *       Filename:  GLTFObject.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_OBJECT_H
#define SOURCE_GLTF_OBJECT_H

#include <string>

namespace GLTF
{

class Object
{
protected:
	Object(void) = default;
	~Object(void) = default;

public:
	inline void SetName(const char* name) { mName = name; }
	inline const char* GetName(void) const { return mName.c_str(); }

protected:
	std::string mName;
};

}

#endif
