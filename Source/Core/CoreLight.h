/*
 * =====================================================================================
 *
 *       Filename:  CoreLight.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_LIGHT_H
#define SOURCE_CORE_LIGHT_H

#include "CoreBase.h"
#include "Math/MathVector.h"

namespace Core
{

enum class LightType : uint32_t
{
	POINT,
    DIRECTIONAL,
    SPOT,
    UNKNOWN = ~0u
};

class Light : public Base
{
public:
	Light(void);
	~Light(void) override ;

public:
	inline LightType GetType(void) const { return m_type; }
	inline void SetType(LightType type) { m_type = type; }

public:
	Math::Vector3f m_direction = {};
	LightType m_type = LightType::UNKNOWN;
};

}

#endif
