/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */

#include <Audio/AudioDevice.h>

#include "ExampleTexture.h"

int main(void)
{
	Audio::Device device;
	device.Init();
	Example::Texture texture;
	texture.Initialize();
	texture.RecordCommands();
	texture.ShowModal();
}

