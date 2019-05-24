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
#include "KernelGuid.h"

#include <iostream>

int main(void)
{
	OpenAL::Device device;
	device.Init();
	Kernel::HashString str("Rook Win");
	std::cout << str << " <Hash> " << str.GetHash() << std::endl;
	for (size_t i = 0; i < 10; ++i)
	{
		Kernel::Guid guid;
		std::cout << " <GUID> " << guid.GetString() << std::endl;
	}
	Example::Texture texture;
	texture.Initialize();
	texture.RecordCommands();
	texture.ShowModal();
}

