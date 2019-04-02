/*
 * AudioObject.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#include "AudioObject.h"

namespace Audio
{

Object::Object(Device& device):
		mDevice(device)
{
}

Object::~Object(void)
{
}

} /* namespace Audio */
