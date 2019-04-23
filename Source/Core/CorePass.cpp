/*
 * CorePath.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "CorePass.h"
#include "CoreSubPass.h"

namespace Core
{

Pass::Pass(System* system):
		Interface(system)
{
}

Pass::~Pass(void)
{
	for (auto sub : mSubPasses)
	{
		delete sub;
	}
	mSubPasses.clear();
}

SubPass* Pass::CreateSubPass(void)
{
	SubPass* sub = new SubPass(this);
	mSubPasses.push_back(sub);
	return sub;
}

} /* namespace Core */
