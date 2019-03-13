/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */

#include "ExampleBuffer.h"

int main(void)
{
	Example::Buffer buffer;
	buffer.Initialize();
	buffer.RecordCommands();
	buffer.ShowModal();
}

