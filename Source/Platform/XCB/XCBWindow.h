/*
 * XCBWindow.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_XCB_XCBWINDOW_H_
#define SOURCE_PLATFORM_XCB_XCBWINDOW_H_

#include "../Core/Platform/PlatformWindow.h"
#include <xcb/xcb.h>

namespace XCB
{

class Window: public Platform::Window
{
public:
	Window(void);
	virtual ~Window(void) override;

public:
	virtual void Create(int width, int height) override;
	virtual bool HandleEvent(void) override;
	virtual void SetTitle(const char* title) override;

public:
	inline xcb_connection_t* GetConnection(void) const { return m_connection; }
	inline xcb_window_t GetWindow(void) const { return m_window; }

private:
	void SetDeleteMode(void);

private:
	xcb_connection_t* m_connection = nullptr;
	xcb_screen_t* m_screen = nullptr;
	xcb_window_t m_window = 0;
	xcb_gcontext_t m_graphic = 0;
	xcb_intern_atom_reply_t* m_atom_wm_delete_window = nullptr;
};

} /* namespace XCB */

#endif /* SOURCE_PLATFORM_XCB_XCBWINDOW_H_ */
