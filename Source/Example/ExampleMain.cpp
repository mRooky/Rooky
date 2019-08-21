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
	std::wcout << str << L" <Hash> ";
	std::wcout << str.GetHash();
	std::wcout << std::endl;
	for (size_t i = 0; i < 10; ++i)
	{
		Kernel::Guid guid;
		std::wcout << L"<GUID>";
		std::wcout << static_cast<const wchar_t*>(guid.GetString());
		std::wcout << std::endl;
	}
	Example::Texture texture;
	texture.Initialize();
	texture.RecordCommands();
	texture.ShowModal();
}

