/*
 * =====================================================================================
 *
 *       Filename:  GLTFNode.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_NODE_H
#define SOURCE_GLTF_NODE_H

#include "../Core/GHI/GHIClasses.h"
#include "../Core/Math/MathTransform.h"
#include <vector>

namespace GLTF
{

class Mesh;
class Node
{
public:
	Node(Node* parent);
	~Node(void);


public:
	void Draw(GHI::CommandList* cmdList);

protected:
	Node* mParent = nullptr;
	std::vector<Node*> mChildren;

protected:
	Mesh* mMesh = nullptr;
	Math::Transform mTransform;

};

}

#endif
