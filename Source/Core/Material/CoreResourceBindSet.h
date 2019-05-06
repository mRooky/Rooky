/*
 * CoreResourceBindingSet.h
 *
 *  Created on: May 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_CORERESOURCEBINDSET_H_
#define SOURCE_CORE_MATERIAL_CORERESOURCEBINDSET_H_

#include "GHIBinding.hpp"
#include <vector>

namespace Core
{

class ResourceBindSet
{
public:
	ResourceBindSet(void);
	~ResourceBindSet(void);

public:
	void PushBinding(const GHI::Binding& binding);
	void PushResource(GHI::Resource* resource, GHI::ShaderStage stage);

public:
	ResourceBindSet& operator+=(const ResourceBindSet& other);

public:
	inline size_t GetBindingCount(void) const { return mBindings.size(); }
	inline const GHI::Binding& GetBinding(size_t index) const { return mBindings.at(index); }

protected:
	std::vector<GHI::Binding> mBindings;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_CORERESOURCEBINDSET_H_ */
