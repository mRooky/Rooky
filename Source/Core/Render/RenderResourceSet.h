/*
 * RenderResourceSet.h
 *
 *  Created on: Feb 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCESET_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCESET_H_

#include "RenderResourceType.h"
#include <vector>

namespace Render
{
class Resource;

class ResourceDesc
{
public:
	ResourceDesc(Resource* resource, ResourceType type): m_resource(resource), m_type(type) {}
	~ResourceDesc(void) = default;

public:
	inline Resource* GetResource(void) const { return m_resource; }
	inline ResourceType GetType(void) const { return m_type; }

private:
	Resource* m_resource = nullptr;
	ResourceType m_type = ResourceType::RESOURCE_TYPE_UNKNOWN;
};

class ResourceSet
{
public:
	ResourceSet(void);
	virtual ~ResourceSet(void);

public:
	void AppendResource(Resource* resource, ResourceType type);

public:
	inline void ClearResource(void) { m_resourceDescs.clear(); }

public:
	inline size_t GetDescCount(void) const { return m_resourceDescs.size(); }
	inline const ResourceDesc& GetDesc(size_t index) const { return m_resourceDescs.at(index); }

private:
	std::vector<ResourceDesc> m_resourceDescs;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCESET_H_ */
