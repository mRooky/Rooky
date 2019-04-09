/*
 * DirectVertex.h
 *
 *  Created on: Oct 12, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTVERTEX_H_
#define DIRECTUI_DIRECTVERTEX_H_

#include "DirectMath.h"
#include "VulkanClasses.h"
#include <vector>

namespace Direct
{

class Vertex
{
public:
	Vertex(void);
	~Vertex(void);

public:
	void SetPosition(float x, float y);
	void SetTexCoord(float u, float v);
	void SetColor(float r, float g, float b, float a);

public:
	void SetColor(const ColorI &color);
	void SetPosition(const Vector2F& position);
	void SetTexCoord(const Vector2F& coord);

public:
	static VkVertexInputBindingDescription GetInputBindingDescription(void);
	static std::vector<VkVertexInputAttributeDescription> GetInputAttributeDescriptions(void);

public:
	inline operator const float*(void) const { return &position.x; }

public:
	ColorI color;
	Vector2F position;
	Vector2F texCoord;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTVERTEX_H_ */
