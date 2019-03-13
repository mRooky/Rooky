/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */

#include "ExampleTexture.h"

int main(void)
{
	Example::Texture texture;
	texture.Initialize();
	texture.RecordCommands();
	texture.ShowModal();
}

