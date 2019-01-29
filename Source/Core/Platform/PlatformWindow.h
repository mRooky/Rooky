/*
 * IOWindow.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_PLATFORM_PLATFORMWINDOW_H_
#define SOURCE_CORE_PLATFORM_PLATFORMWINDOW_H_

namespace Platform
{

class Window
{
public:
	Window(void);
	virtual ~Window(void);

public:
	virtual void Create(int width, int height) = 0;
	virtual bool HandleEvent(void) = 0;
	virtual void SetTitle(const char* title) = 0;
};

} /* namespace IO */

#endif /* SOURCE_CORE_PLATFORM_PLATFORMWINDOW_H_ */
