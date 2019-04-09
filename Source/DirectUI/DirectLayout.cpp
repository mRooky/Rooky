/*
 * DirectLayout.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#include "DirectLayout.h"

namespace Direct
{

Layout::Layout(Widget* parent):
		Container(parent)
{
}

Layout::~Layout(void)
{
	mSpace = 0;
}

} /* namespace Direct */
