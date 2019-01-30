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
class Mouse;
class Keyboard;
class Window
{
protected:
	Window(void);

public:
	virtual ~Window(void);

public:
	virtual void Create(int width, int height) = 0;
	virtual bool HandleEvent(void) = 0;
	virtual void SetTitle(const char* title) = 0;

public:
	inline Mouse* GetMouse(void) const { return mMouse; }
	inline Keyboard* GetKeyboard(void) const { return mKeyboard; }

protected:
	Mouse* mMouse = nullptr;
	Keyboard* mKeyboard = nullptr;
};

} /* namespace IO */

#endif /* SOURCE_CORE_PLATFORM_PLATFORMWINDOW_H_ */
