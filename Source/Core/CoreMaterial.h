/*
 * CoreMaterial.h
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMATERIAL_H_
#define SOURCE_CORE_COREMATERIAL_H_

#include <vector>

namespace Core
{
class Pass;
class Material
{
public:
	Material(void);
	virtual ~Material(void);

public:
	Pass* CreatePass(void);

public:
	inline Pass* GetPass(size_t index) const { return mPasses.at(index); }

protected:
	std::vector<Pass*> mPasses;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMATERIAL_H_ */
