/*
 * CorePath.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "CorePath.h"
#include "CorePass.h"

namespace Core
{

Path::Path(System* system):
		Interface(system)
{
}

Path::~Path(void)
{
	for (auto pass : mPasses)
	{
		delete pass;
	}
	mPasses.clear();
}

Pass* Path::CreatePass(void)
{
	Pass* pass = new Pass(this);
	mPasses.push_back(pass);
	return pass;
}

} /* namespace Core */
