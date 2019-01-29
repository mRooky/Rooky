/*
 * Main.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: rookyma
 */

#include "Platform/XCB/XCBWindow.h"

int main(void)
{
	XCB::Window window;
	window.Create(1280, 800);
	window.SetTitle("Rooky Window");
	bool done = false;
	while (!done)
	{
		done = window.HandleEvent();
	}
	return 0;
}

