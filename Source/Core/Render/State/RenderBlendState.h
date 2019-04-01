/*
 * RenderBlendState.h
 *
 *  Created on: Apr 1, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_STATE_RENDERBLENDSTATE_H_
#define SOURCE_CORE_RENDER_STATE_RENDERBLENDSTATE_H_

#include "RenderColorBlend.h"
#include <vector>

namespace Render
{

class BlendState
{
public:
	BlendState(void);
	~BlendState(void);

public:
	bool operator==(const BlendState& other) const;

public:
	inline size_t GetColorBlendCount(void) const { return mColorBlends.size(); }
	inline void SetColorBlend(const ColorBlend& blend) { mColorBlends.push_back(blend); }
	inline const ColorBlend& GetColorBlend(size_t index) const { return mColorBlends.at(index); }

protected:
	std::vector<ColorBlend> mColorBlends = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_STATE_RENDERBLENDSTATE_H_ */
