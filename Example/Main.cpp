/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */

#include "Base/ExampleBuffer.h"

int main(void)
{
	Example::Buffer buffer;
	buffer.CreateWindow("Rooky Window");
	buffer.CreateSystem();
	buffer.CreateBuffer();
	buffer.ShowModal();
}

