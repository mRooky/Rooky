/*
 * CoreResourceBindingSet.cpp
 *
 *  Created on: May 6, 2019
 *      Author: rookyma
 */

#include "CoreResourceBindSet.h"
#include "UtilitySearch.h"

namespace Core
{

ResourceBindSet::ResourceBindSet(void)
{
}

ResourceBindSet::~ResourceBindSet(void)
{
}

void ResourceBindSet::Append(const ResourceBindSet& other)
{
	const size_t count = other.GetBindingCount();
	for (size_t index = 0; index < count; ++index)
	{
		const GHI::Binding& binding = other.GetBinding(index);
		PushBinding(binding);
	}
}

void ResourceBindSet::PushBinding(const GHI::Binding& binding)
{
	auto iterator = Utility::Find(mBindings, binding);
	if (iterator == mBindings.end())
	{
		mBindings.push_back(binding);
	}
}

void ResourceBindSet::PushResource(GHI::Resource* resource, GHI::ShaderStage stage)
{
	GHI::Binding binding;
	binding.SetResource(resource, stage);
	PushBinding(binding);
}

} /* namespace Core */
