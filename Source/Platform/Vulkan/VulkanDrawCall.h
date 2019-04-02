/*
 * VulkanDrawCall.h
 *
 *  Created on: Sep 2, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDRAWCALL_H_
#define VULKAN_VULKANDRAWCALL_H_

#include "VulkanClasses.h"
#include "VulkanObject.h"

namespace Vulkan
{
class ROOKY_EXPORT DrawCall : public Object
{
protected:
	DrawCall(void);
	virtual ~DrawCall(void) override;

public:
	virtual void Record(CommandBuffer* command) = 0;
};

class ROOKY_EXPORT DrawDirect : public DrawCall
{
public:
	DrawDirect(void);
	virtual ~DrawDirect(void) override;

public:
	inline uint32_t GetInstanceCount(void) const { return mInstanceCount; }
	inline uint32_t GetFirstInstance(void) const { return mFirstInstance; }
	inline void SetInstanceCount(uint32_t count) { mInstanceCount = count; }
	inline void SetFirstInstance(uint32_t first) { mFirstInstance = first; }

protected:
	uint32_t mInstanceCount = 1;
	uint32_t mFirstInstance = 0;
};

class ROOKY_EXPORT DrawArray : public DrawDirect
{
public:
	DrawArray(void);
	virtual ~DrawArray(void) override;

public:
	VkDrawIndirectCommand GetIndirectCommand(void) const;

public:
	virtual void Record(CommandBuffer* command) override;

public:
	inline uint32_t GetVertexCount(void) const { return mVertexCount; }
	inline uint32_t GetFirstVertex(void) const { return mFirstVertex; }
	inline void SetVertexCount(uint32_t count) { mVertexCount = count; }
	inline void SetFirstVertex(uint32_t first) { mFirstVertex = first; }

protected:
	uint32_t mVertexCount = 0;
	uint32_t mFirstVertex = 0;
};

class ROOKY_EXPORT DrawIndexed : public DrawDirect
{
public:
	DrawIndexed(void);
	virtual ~DrawIndexed(void) override;

public:
	VkDrawIndexedIndirectCommand GetIndirectCommand(void) const;

public:
	virtual void Record(CommandBuffer* command) override;

public:
	inline uint32_t GetIndexCount(void) const { return mIndexCount; }
	inline uint32_t GetFirstIndex(void) const { return mFirstIndex; }
	inline uint32_t GetVertexOffset(void) const { return mVertexOffset; }
	inline void SetIndexCount(uint32_t count) { mIndexCount = count; }
	inline void SetFirstIndex(uint32_t first) { mFirstIndex = first; }
	inline void SetVertexOffset(uint32_t offset) { mVertexOffset = offset; }

protected:
	uint32_t mIndexCount = 0;
	uint32_t mFirstIndex = 0;
	uint32_t mVertexOffset = 0;
};

class ROOKY_EXPORT DrawIndirect : public DrawCall
{
public:
	DrawIndirect(void);
	virtual ~DrawIndirect(void) override;

public:
	virtual void Record(CommandBuffer* command) override;

public:
	void Create(Device* device, size_t size);
	uint32_t Write(uint32_t offset, DrawArray* draw);

public:
	inline size_t GetSize(void) const { return mSize; }
	inline Buffer* GetBuffer(void) const { return mBuffer; }
	inline uint32_t GetOffset(void) const { return mOffset; }
	inline uint32_t GetDrawCount(void) const { return mDrawCount; }
	inline uint32_t GetStride(void) const { return mStride; }

public:
	inline void SetOffset(uint32_t offset) { mOffset = offset; }
	inline void SetDrawCount(uint32_t count) { mDrawCount = count; }

protected:
	size_t mSize = 0;

protected:
	Buffer* mBuffer = nullptr;

protected:
	uint32_t mOffset = 0;
	uint32_t mDrawCount = 0;
	uint32_t mStride = 0;

private:
	DeviceMemory* m_memory = nullptr;
};

class ROOKY_EXPORT DrawIndexedIndirect : public DrawIndirect
{
protected:
	DrawIndexedIndirect(void);
	virtual ~DrawIndexedIndirect(void) override;

public:
	virtual void Record(CommandBuffer* command) override;

public:
	uint32_t Write(uint32_t offset, DrawIndexed* draw);
};


} /* namespace Vulkan */

#endif /* VULKAN_VULKANDRAWCALL_H_ */
