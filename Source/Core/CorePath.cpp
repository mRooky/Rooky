/*
 * CorePath.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "CoreSubPath.h"
#include "CorePath.h"

namespace Core
{

Path::Path(System* system):
		Interface(system)
{
}

Path::~Path(void)
{
	for (auto sub : mSubPathes)
	{
		delete sub;
	}
	mSubPathes.clear();
}

SubPath* Path::CreateSubPath(void)
{
	SubPath* sub = new SubPath(this);
	mSubPathes.push_back(sub);
	return sub;
}

} /* namespace Core */
