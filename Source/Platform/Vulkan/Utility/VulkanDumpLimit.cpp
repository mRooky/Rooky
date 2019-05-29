/*
 * VulkanCommon.cpp
 *
 *  Created on: Dec 12, 2018
 *      Author: rookyma
 */

#include "VulkanDumpLimit.h"
#include "../VulkanPhysicalDevice.h"
#include "../VulkanVendor.h"
#include <cinttypes>
#include <iostream>

#define PRINTF_SIZE_T_SPECIFIER    "%zu"

namespace Vulkan
{

void DumpLimits(const PhysicalDevice* device)
{
	const VkPhysicalDeviceProperties& properties = device->GetProperties();
	const VkPhysicalDeviceLimits* limits = &properties.limits;

	std::cout << "Physical Device Name : " << properties.deviceName << std::endl;
	std::cout << Vulkan::Vendor::VersionString(properties.apiVersion) << std::endl;

	printf("Limits:\n");
	printf("-----------------------\n");
	printf("\tmaxImageDimension1D                     = %u\n",                 limits->maxImageDimension1D                    );
	printf("\tmaxImageDimension2D                     = %u\n",                 limits->maxImageDimension2D                    );
	printf("\tmaxImageDimension3D                     = %u\n",                 limits->maxImageDimension3D                    );
	printf("\tmaxImageDimensionCube                   = %u\n",                 limits->maxImageDimensionCube                  );
	printf("\tmaxImageArrayLayers                     = %u\n",                 limits->maxImageArrayLayers                    );
	printf("\tmaxTexelBufferElements                  = 0x%" PRIxLEAST32 "\n", limits->maxTexelBufferElements                 );
	printf("\tmaxUniformBufferRange                   = 0x%" PRIxLEAST32 "\n", limits->maxUniformBufferRange                  );
	printf("\tmaxStorageBufferRange                   = 0x%" PRIxLEAST32 "\n", limits->maxStorageBufferRange                  );
	printf("\tmaxPushConstantsSize                    = %u\n",                 limits->maxPushConstantsSize                   );
	printf("\tmaxMemoryAllocationCount                = %u\n",                 limits->maxMemoryAllocationCount               );
	printf("\tmaxSamplerAllocationCount               = %u\n",                 limits->maxSamplerAllocationCount              );
	printf("\tbufferImageGranularity                  = 0x%" PRIxLEAST64 "\n", limits->bufferImageGranularity                 );
	printf("\tsparseAddressSpaceSize                  = 0x%" PRIxLEAST64 "\n", limits->sparseAddressSpaceSize                 );
	printf("\tmaxBoundDescriptorSets                  = %u\n",                 limits->maxBoundDescriptorSets                 );
	printf("\tmaxPerStageDescriptorSamplers           = %u\n",                 limits->maxPerStageDescriptorSamplers          );
	printf("\tmaxPerStageDescriptorUniformBuffers     = %u\n",                 limits->maxPerStageDescriptorUniformBuffers    );
	printf("\tmaxPerStageDescriptorStorageBuffers     = %u\n",                 limits->maxPerStageDescriptorStorageBuffers    );
	printf("\tmaxPerStageDescriptorSampledImages      = %u\n",                 limits->maxPerStageDescriptorSampledImages     );
	printf("\tmaxPerStageDescriptorStorageImages      = %u\n",                 limits->maxPerStageDescriptorStorageImages     );
	printf("\tmaxPerStageDescriptorInputAttachments   = %u\n",                 limits->maxPerStageDescriptorInputAttachments  );
	printf("\tmaxPerStageResources                    = %u\n",                 limits->maxPerStageResources                   );
	printf("\tmaxDescriptorSetSamplers                = %u\n",                 limits->maxDescriptorSetSamplers               );
	printf("\tmaxDescriptorSetUniformBuffers          = %u\n",                 limits->maxDescriptorSetUniformBuffers         );
	printf("\tmaxDescriptorSetUniformBuffersDynamic   = %u\n",                 limits->maxDescriptorSetUniformBuffersDynamic  );
	printf("\tmaxDescriptorSetStorageBuffers          = %u\n",                 limits->maxDescriptorSetStorageBuffers         );
	printf("\tmaxDescriptorSetStorageBuffersDynamic   = %u\n",                 limits->maxDescriptorSetStorageBuffersDynamic  );
	printf("\tmaxDescriptorSetSampledImages           = %u\n",                 limits->maxDescriptorSetSampledImages          );
	printf("\tmaxDescriptorSetStorageImages           = %u\n",                 limits->maxDescriptorSetStorageImages          );
	printf("\tmaxDescriptorSetInputAttachments        = %u\n",                 limits->maxDescriptorSetInputAttachments       );
	printf("\tmaxVertexInputAttributes                = %u\n",                 limits->maxVertexInputAttributes               );
	printf("\tmaxVertexInputBindings                  = %u\n",                 limits->maxVertexInputBindings                 );
	printf("\tmaxVertexInputAttributeOffset           = 0x%" PRIxLEAST32 "\n", limits->maxVertexInputAttributeOffset          );
	printf("\tmaxVertexInputBindingStride             = 0x%" PRIxLEAST32 "\n", limits->maxVertexInputBindingStride            );
	printf("\tmaxVertexOutputComponents               = %u\n",                 limits->maxVertexOutputComponents              );
	printf("\tmaxTessellationGenerationLevel          = %u\n",                 limits->maxTessellationGenerationLevel         );
	printf("\tmaxTessellationPatchSize                        = %u\n",                 limits->maxTessellationPatchSize                       );
	printf("\tmaxTessellationControlPerVertexInputComponents  = %u\n",                 limits->maxTessellationControlPerVertexInputComponents );
	printf("\tmaxTessellationControlPerVertexOutputComponents = %u\n",                 limits->maxTessellationControlPerVertexOutputComponents);
	printf("\tmaxTessellationControlPerPatchOutputComponents  = %u\n",                 limits->maxTessellationControlPerPatchOutputComponents );
	printf("\tmaxTessellationControlTotalOutputComponents     = %u\n",                 limits->maxTessellationControlTotalOutputComponents    );
	printf("\tmaxTessellationEvaluationInputComponents        = %u\n",                 limits->maxTessellationEvaluationInputComponents       );
	printf("\tmaxTessellationEvaluationOutputComponents       = %u\n",                 limits->maxTessellationEvaluationOutputComponents      );
	printf("\tmaxGeometryShaderInvocations            = %u\n",                 limits->maxGeometryShaderInvocations           );
	printf("\tmaxGeometryInputComponents              = %u\n",                 limits->maxGeometryInputComponents             );
	printf("\tmaxGeometryOutputComponents             = %u\n",                 limits->maxGeometryOutputComponents            );
	printf("\tmaxGeometryOutputVertices               = %u\n",                 limits->maxGeometryOutputVertices              );
	printf("\tmaxGeometryTotalOutputComponents        = %u\n",                 limits->maxGeometryTotalOutputComponents       );
	printf("\tmaxFragmentInputComponents              = %u\n",                 limits->maxFragmentInputComponents             );
	printf("\tmaxFragmentOutputAttachments            = %u\n",                 limits->maxFragmentOutputAttachments           );
	printf("\tmaxFragmentDualSrcAttachments           = %u\n",                 limits->maxFragmentDualSrcAttachments          );
	printf("\tmaxFragmentCombinedOutputResources      = %u\n",                 limits->maxFragmentCombinedOutputResources     );
	printf("\tmaxComputeSharedMemorySize              = 0x%" PRIxLEAST32 "\n", limits->maxComputeSharedMemorySize             );
	printf("\tmaxComputeWorkGroupCount[0]             = %u\n",                 limits->maxComputeWorkGroupCount[0]            );
	printf("\tmaxComputeWorkGroupCount[1]             = %u\n",                 limits->maxComputeWorkGroupCount[1]            );
	printf("\tmaxComputeWorkGroupCount[2]             = %u\n",                 limits->maxComputeWorkGroupCount[2]            );
	printf("\tmaxComputeWorkGroupInvocations          = %u\n",                 limits->maxComputeWorkGroupInvocations         );
	printf("\tmaxComputeWorkGroupSize[0]              = %u\n",                 limits->maxComputeWorkGroupSize[0]             );
	printf("\tmaxComputeWorkGroupSize[1]              = %u\n",                 limits->maxComputeWorkGroupSize[1]             );
	printf("\tmaxComputeWorkGroupSize[2]              = %u\n",                 limits->maxComputeWorkGroupSize[2]             );
	printf("\tsubPixelPrecisionBits                   = %u\n",                 limits->subPixelPrecisionBits                  );
	printf("\tsubTexelPrecisionBits                   = %u\n",                 limits->subTexelPrecisionBits                  );
	printf("\tmipmapPrecisionBits                     = %u\n",                 limits->mipmapPrecisionBits                    );
	printf("\tmaxDrawIndexedIndexValue                = %u\n",                 limits->maxDrawIndexedIndexValue               );
	printf("\tmaxDrawIndirectCount                    = %u\n",                 limits->maxDrawIndirectCount                   );
	printf("\tmaxSamplerLodBias                       = %f\n",                 limits->maxSamplerLodBias                      );
	printf("\tmaxSamplerAnisotropy                    = %f\n",                 limits->maxSamplerAnisotropy                   );
	printf("\tmaxViewports                            = %u\n",                 limits->maxViewports                           );
	printf("\tmaxViewportDimensions[0]                = %u\n",                 limits->maxViewportDimensions[0]               );
	printf("\tmaxViewportDimensions[1]                = %u\n",                 limits->maxViewportDimensions[1]               );
	printf("\tviewportBoundsRange[0]                  = %13f\n",               limits->viewportBoundsRange[0]                 );
	printf("\tviewportBoundsRange[1]                  = %13f\n",               limits->viewportBoundsRange[1]                 );
	printf("\tviewportSubPixelBits                    = %u\n",                 limits->viewportSubPixelBits                   );
	printf("\tminMemoryMapAlignment                   = " PRINTF_SIZE_T_SPECIFIER "\n", limits->minMemoryMapAlignment         );
	printf("\tminTexelBufferOffsetAlignment           = 0x%" PRIxLEAST64 "\n", limits->minTexelBufferOffsetAlignment          );
	printf("\tminUniformBufferOffsetAlignment         = 0x%" PRIxLEAST64 "\n", limits->minUniformBufferOffsetAlignment        );
	printf("\tminStorageBufferOffsetAlignment         = 0x%" PRIxLEAST64 "\n", limits->minStorageBufferOffsetAlignment        );
	printf("\tminTexelOffset                          = %3d\n",                limits->minTexelOffset                         );
	printf("\tmaxTexelOffset                          = %3d\n",                limits->maxTexelOffset                         );
	printf("\tminTexelGatherOffset                    = %3d\n",                limits->minTexelGatherOffset                   );
	printf("\tmaxTexelGatherOffset                    = %3d\n",                limits->maxTexelGatherOffset                   );
	printf("\tminInterpolationOffset                  = %9f\n",                limits->minInterpolationOffset                 );
	printf("\tmaxInterpolationOffset                  = %9f\n",                limits->maxInterpolationOffset                 );
	printf("\tsubPixelInterpolationOffsetBits         = %u\n",                 limits->subPixelInterpolationOffsetBits        );
	printf("\tmaxFramebufferWidth                     = %u\n",                 limits->maxFramebufferWidth                    );
	printf("\tmaxFramebufferHeight                    = %u\n",                 limits->maxFramebufferHeight                   );
	printf("\tmaxFramebufferLayers                    = %u\n",                 limits->maxFramebufferLayers                   );
	printf("\tframebufferColorSampleCounts            = %u\n",                 limits->framebufferColorSampleCounts           );
	printf("\tframebufferDepthSampleCounts            = %u\n",                 limits->framebufferDepthSampleCounts           );
	printf("\tframebufferStencilSampleCounts          = %u\n",                 limits->framebufferStencilSampleCounts         );
	printf("\tframebufferNoAttachmentsSampleCounts    = %u\n",                 limits->framebufferNoAttachmentsSampleCounts   );
	printf("\tmaxColorAttachments                     = %u\n",                 limits->maxColorAttachments                    );
	printf("\tsampledImageColorSampleCounts           = %u\n",                 limits->sampledImageColorSampleCounts          );
	printf("\tsampledImageDepthSampleCounts           = %u\n",                 limits->sampledImageDepthSampleCounts          );
	printf("\tsampledImageStencilSampleCounts         = %u\n",                 limits->sampledImageStencilSampleCounts        );
	printf("\tsampledImageIntegerSampleCounts         = %u\n",                 limits->sampledImageIntegerSampleCounts        );
	printf("\tstorageImageSampleCounts                = %u\n",                 limits->storageImageSampleCounts               );
	printf("\tmaxSampleMaskWords                      = %u\n",                 limits->maxSampleMaskWords                     );
	printf("\ttimestampComputeAndGraphics             = %u\n",                 limits->timestampComputeAndGraphics            );
	printf("\ttimestampPeriod                         = %f\n",                 limits->timestampPeriod                        );
	printf("\tmaxClipDistances                        = %u\n",                 limits->maxClipDistances                       );
	printf("\tmaxCullDistances                        = %u\n",                 limits->maxCullDistances                       );
	printf("\tmaxCombinedClipAndCullDistances         = %u\n",                 limits->maxCombinedClipAndCullDistances        );
	printf("\tdiscreteQueuePriorities                 = %u\n",                 limits->discreteQueuePriorities                );
	printf("\tpointSizeRange[0]                       = %f\n",                 limits->pointSizeRange[0]                      );
	printf("\tpointSizeRange[1]                       = %f\n",                 limits->pointSizeRange[1]                      );
	printf("\tlineWidthRange[0]                       = %f\n",                 limits->lineWidthRange[0]                      );
	printf("\tlineWidthRange[1]                       = %f\n",                 limits->lineWidthRange[1]                      );
	printf("\tpointSizeGranularity                    = %f\n",                 limits->pointSizeGranularity                   );
	printf("\tlineWidthGranularity                    = %f\n",                 limits->lineWidthGranularity                   );
	printf("\tstrictLines                             = %u\n",                 limits->strictLines                            );
	printf("\tstandardSampleLocations                 = %u\n",                 limits->standardSampleLocations                );
	printf("\toptimalBufferCopyOffsetAlignment        = 0x%" PRIxLEAST64 "\n", limits->optimalBufferCopyOffsetAlignment       );
	printf("\toptimalBufferCopyRowPitchAlignment      = 0x%" PRIxLEAST64 "\n", limits->optimalBufferCopyRowPitchAlignment     );
	printf("\tnonCoherentAtomSize                     = 0x%" PRIxLEAST64 "\n", limits->nonCoherentAtomSize                    );
}

} /* namespace Vulkan */
