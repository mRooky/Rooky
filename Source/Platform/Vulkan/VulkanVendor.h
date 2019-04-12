/*
 * VulkanVendor.h
 *
 *  Created on: Dec 8, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANVENDOR_H_
#define VULKAN_VULKANVENDOR_H_

#include "VulkanObject.h"
#include <vector>
#include <string>

namespace Vulkan
{

class VULKAN_EXPORT Vendor : public Object
{
private:
	Vendor(void);
	virtual ~Vendor(void) override;

public:
	void Init(void);

public:
	std::string GetVersion(void) const;

public:
	bool DoesLayerExist(const char* layer) const;
	bool DoesExtensionExist(const char* extension) const;

public:
	inline uint32_t GetMajor(void) const { return m_major; }
	inline uint32_t GetMinor(void) const { return m_minor; }
	inline uint32_t GetPatch(void) const { return m_patch; }

public:
	static inline Vendor* New(void) { return new Vendor; }

public:
	static std::string VersionString(uint32_t version);

private:
	void GetLayers(void);
	void GetExtensions(const char* layer);

private:
	uint32_t m_major = 0;
	uint32_t m_minor = 0;
	uint32_t m_patch = 0;

private:
	std::vector<std::string> m_layerNames;
	std::vector<std::string> m_extensionNames;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANVENDOR_H_ */
