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
	ResourceDesc(Resource* resource, ResourceType type):
		m_resource(resource), m_type(type) {}
	~ResourceDesc(void) = default;

public:
	inline ResourceType GetType(void) const { return m_type; }
	inline Resource* GetResource(void) const { return m_resource; }

private:
	Resource* m_resource = nullptr;
	ResourceType m_type = ResourceType::RESOURCE_TYPE_UNKNOWN;
};

class ResourceSet
{
protected:
	ResourceSet(void);

public:
	virtual ~ResourceSet(void);

public:
	void AppendResource(Resource* resource, ResourceType type);

public:
	inline void ClearResource(void) { mResourceDescs.clear(); }

public:
	inline size_t GetDescCount(void) const { return mResourceDescs.size(); }
	inline const ResourceDesc& GetDesc(size_t index) const { return mResourceDescs.at(index); }

protected:
	std::vector<ResourceDesc> mResourceDescs;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCESET_H_ */
