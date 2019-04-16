/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */

#include "AudioDevice.h"

#include "ExampleTexture.h"
#include "KernelCompile.h"

int main(void)
{
	Audio::Device device;
	device.Init();
	ComplieTest(__FILE__);
	Example::Texture texture;
	texture.Initialize();
	texture.RecordCommands();
	texture.ShowModal();
}

