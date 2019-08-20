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

private:
	Node* m_parent = nullptr;
	std::vector<Node*> m_children;

private:
	Mesh* m_mesh = nullptr;

};

}

#endif
