/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */

#include "OpenALDevice.h"

#include "ExampleTexture.h"
#include "KernelString.h"
#include "KernelFile.h"

int main(void)
{
	OpenAL::Device device;
	device.Init();
	Kernel::HashString str("Rook Win");
	str.Print();
	Example::Texture texture;
	texture.Initialize();
	texture.RecordCommands();
	texture.ShowModal();
}

