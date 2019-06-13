/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */


#include "ExampleTexture.h"
#include "../Platform/OpenAL/OpenALDevice.h"
#include "../Core/Kernel/KernelFile.h"
#include "../Core/Kernel/KernelGuid.h"
#include "../Core/Kernel/KernelHashString.h"

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

