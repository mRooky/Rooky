/*
 * CoreData.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: rookyma
 */


#include "CoreData.h"
#include <cassert>

namespace Core
{

Data::Data(void)
{
}

Data::~Data(void)
{
	FreeMemory();
}

void Data::FreeMemory(void)
{
	mSize = 0;
	delete[] mMemory;
	mMemory = nullptr;
}

void Data::AllocateMemory(size_t size)
{
	assert(size > 0);
	mSize = size;
	mMemory = new uint8_t[size];
}

}
