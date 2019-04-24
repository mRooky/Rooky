/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */

#include "OpenALDevice.h"

#include "ExampleTexture.h"
#include "KernelCompile.h"

int main(void)
{
	OpenAL::Device device;
	device.Init();
	Kernel::StringHash("Rook Win");
	Example::Texture texture;
	texture.Initialize();
	texture.RecordCommands();
	texture.ShowModal();
}

