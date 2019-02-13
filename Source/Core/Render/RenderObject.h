/*
 * RenderObject.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDEROBJECT_H_
#define SOURCE_CORE_RENDER_RENDEROBJECT_H_

namespace Render
{
class Context;
class Object
{
protected:
	explicit Object(Context* context);

public:
	virtual ~Object(void);

public:
	inline Context* GetContext(void) const { return mContext; }

protected:
	Context* mContext = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDEROBJECT_H_ */
