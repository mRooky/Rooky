/*
 * Base.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#include "VulkanBase.h"

#include <cxxabi.h>
#include <string>
#include <cassert>
#include <iostream>

namespace Vulkan
{

Base::Base(void) = default;
Base::~Base(void) = default;

std::string Base::GetClassName(void) const
{
	int status = 0;
	char* rtti = abi::__cxa_demangle(typeid(*this).name(), nullptr, nullptr, &status);
	std::string name = rtti;
	std::free(rtti);
	return name;
}

void Base::Destroy(void)
{
	std::cout<< "Vulkan Destroy : " << GetClassName() << std::endl;
	delete this;
}

} /* namespace Vulkan */
