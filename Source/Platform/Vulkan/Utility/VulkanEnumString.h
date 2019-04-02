/*
 * VulkanEnumString.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef VULKAN_COMMON_VULKANENUMSTRING_H_
#define VULKAN_COMMON_VULKANENUMSTRING_H_

#include <vulkan/vulkan.h>

namespace Vulkan
{

const char* AttachmentLoadOpString(VkAttachmentLoadOp input);
const char* AttachmentStoreOpString(VkAttachmentStoreOp input);
const char* BlendFactorString(VkBlendFactor input);
const char* BlendOpString(VkBlendOp input);
const char* BlendOverlapEXTString(VkBlendOverlapEXT input);
const char* BorderColorString(VkBorderColor input);
const char* ChromaLocationString(VkChromaLocation input);
const char* ColorSpaceKHRString(VkColorSpaceKHR input);
const char* CommandBufferLevelString(VkCommandBufferLevel input);
const char* CompareOpString(VkCompareOp input);
const char* ComponentSwizzleString(VkComponentSwizzle input);
const char* ConservativeRasterizationModeEXTString(VkConservativeRasterizationModeEXT input);
const char* CoverageModulationModeNVString(VkCoverageModulationModeNV input);
const char* DebugReportObjectTypeEXTString(VkDebugReportObjectTypeEXT input);
const char* DescriptorTypeString(VkDescriptorType input);
const char* DescriptorUpdateTemplateTypeString(VkDescriptorUpdateTemplateType input);
const char* DeviceEventTypeEXTString(VkDeviceEventTypeEXT input);
const char* DiscardRectangleModeEXTString(VkDiscardRectangleModeEXT input);
const char* DisplayEventTypeEXTString(VkDisplayEventTypeEXT input);
const char* DisplayPowerStateEXTString(VkDisplayPowerStateEXT input);
const char* DynamicStateString(VkDynamicState input);
const char* FilterString(VkFilter input);
const char* FormatString(VkFormat input);
const char* FrontFaceString(VkFrontFace input);
const char* ImageLayoutString(VkImageLayout input);
const char* ImageTilingString(VkImageTiling input);
const char* ImageTypeString(VkImageType input);
const char* ImageViewTypeString(VkImageViewType input);
const char* IndexTypeString(VkIndexType input);
const char* IndirectCommandsTokenTypeNVXString(VkIndirectCommandsTokenTypeNVX input);
const char* InternalAllocationTypeString(VkInternalAllocationType input);
const char* LogicOpString(VkLogicOp input);
const char* ObjectEntryTypeNVXString(VkObjectEntryTypeNVX input);
const char* ObjectTypeString(VkObjectType input);
const char* PhysicalDeviceTypeString(VkPhysicalDeviceType input);
const char* PipelineBindPointString(VkPipelineBindPoint input);
const char* PipelineCacheHeaderVersionString(VkPipelineCacheHeaderVersion input);
const char* PointClippingBehaviorString(VkPointClippingBehavior input);
const char* PolygonModeString(VkPolygonMode input);
const char* PresentModeKHRString(VkPresentModeKHR input);
const char* PrimitiveTopologyString(VkPrimitiveTopology input);
const char* QueryTypeString(VkQueryType input);
const char* QueueGlobalPriorityEXTString(VkQueueGlobalPriorityEXT input);
const char* RasterizationOrderAMDString(VkRasterizationOrderAMD input);
const char* ResultString(VkResult input);
const char* SamplerAddressModeString(VkSamplerAddressMode input);
const char* SamplerMipmapModeString(VkSamplerMipmapMode input);
const char* SamplerReductionModeEXTString(VkSamplerReductionModeEXT input);
const char* SamplerYcbcrModelConversionString(VkSamplerYcbcrModelConversion input);
const char* SamplerYcbcrRangeString(VkSamplerYcbcrRange input);
const char* ShaderInfoTypeAMDString(VkShaderInfoTypeAMD input);
const char* SharingModeString(VkSharingMode input);
const char* StencilOpString(VkStencilOp input);
const char* StructureTypeString(VkStructureType input);
const char* SubpassContentsString(VkSubpassContents input);
const char* SystemAllocationScopeString(VkSystemAllocationScope input);
const char* TessellationDomainOriginString(VkTessellationDomainOrigin input);
const char* ValidationCacheHeaderVersionEXTString(VkValidationCacheHeaderVersionEXT input);
const char* ValidationCheckEXTString(VkValidationCheckEXT input);
const char* VendorIdString(VkVendorId input);
const char* VertexInputRateString(VkVertexInputRate input);
const char* ViewportCoordinateSwizzleNVString(VkViewportCoordinateSwizzleNV input);

} /* namespace Vulkan */

#endif /* VULKAN_COMMON_VULKANENUMSTRING_H_ */
