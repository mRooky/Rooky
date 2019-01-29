/*
 * RenderCommandList.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERCOMMANDLIST_H_
#define SOURCE_CORE_RENDER_RENDERCOMMANDLIST_H_

namespace Render
{
class CommandPool;
class CommandList
{
	friend class CommandPool;
protected:
	explicit CommandList(CommandPool* pool);
	virtual ~CommandList(void);

public:
	virtual void Initialize(bool primary) = 0;

public:
	inline CommandPool* GetCommandPool(void) const { return mCommandPool; }

protected:
	CommandPool* mCommandPool = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCOMMANDLIST_H_ */
