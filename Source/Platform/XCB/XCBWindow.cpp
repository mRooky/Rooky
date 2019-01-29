/*
 * XCBWindow.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "XCBWindow.h"
#include <cstring>
#include <cassert>
#include <cstdlib>

namespace XCB
{

Window::Window(void)
{
}

Window::~Window(void)
{
	if (m_atom_wm_delete_window != nullptr)
	{
		std::free(m_atom_wm_delete_window);
		m_atom_wm_delete_window = nullptr;
	}

	if (m_connection != nullptr)
	{
		xcb_disconnect(m_connection);
		m_connection = nullptr;
	}
}

void Window::Create(int width, int height)
{
	int num = 0;
	m_connection = xcb_connect(nullptr, &num);
	assert(m_connection != nullptr);
	const struct xcb_setup_t* setup = xcb_get_setup(m_connection);
	xcb_screen_iterator_t iterator = xcb_setup_roots_iterator(setup);
	m_screen = iterator.data;
	m_graphic = xcb_generate_id(m_connection);
	m_window = m_screen->root;

	uint32_t mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
	uint32_t values[2];
	values[0] = m_screen->black_pixel;
	values[1] = 0;
	xcb_create_gc(m_connection, m_graphic, m_window, mask, values);
	m_window = xcb_generate_id(m_connection);

	mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
	values[0] = m_screen->white_pixel;
	values[1] = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS
			| XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_BUTTON_PRESS
			| XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_STRUCTURE_NOTIFY
			| XCB_EVENT_MASK_POINTER_MOTION;
	xcb_create_window(m_connection, m_screen->root_depth, m_window,
			m_screen->root, 10, 10, width, height, 1,
			XCB_WINDOW_CLASS_INPUT_OUTPUT, m_screen->root_visual, mask, values);

	SetDeleteMode();
	const char *title = "Vulkan";
	SetTitle(title);
	xcb_map_window(m_connection, m_window);
	xcb_flush(m_connection);
}

static inline xcb_intern_atom_reply_t* intern_atom_helper(xcb_connection_t *connection, bool only_if_exists, const char *str)
{
	xcb_intern_atom_cookie_t cookie = xcb_intern_atom(connection, only_if_exists, strlen(str), str);
	xcb_intern_atom_reply_t* reply =  xcb_intern_atom_reply(connection, cookie, nullptr);
	return reply;
}

void Window::SetDeleteMode(void)
{
	xcb_intern_atom_reply_t* reply = intern_atom_helper(m_connection, true,	"WM_PROTOCOLS");
	m_atom_wm_delete_window = intern_atom_helper(
			m_connection, false, "WM_DELETE_WINDOW");

	xcb_change_property(m_connection, XCB_PROP_MODE_REPLACE, m_window,
			reply->atom, 4, 32, 1, &m_atom_wm_delete_window->atom);

	std::free(reply);
}

void Window::SetTitle(const char* title)
{
	unsigned length = strlen(title);
	xcb_change_property(m_connection, XCB_PROP_MODE_REPLACE, m_window,
			XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8, length, title);
}

bool Window::HandleEvent(void)
{
	xcb_generic_event_t *event;
	xcb_client_message_event_t* message = nullptr;
	bool done = false;
	xcb_flush(m_connection);
	event = xcb_poll_for_event(m_connection);
	if (event != nullptr)
	{
		switch (event->response_type & ~0x80)
		{
		case XCB_EXPOSE:
			break;
		case XCB_KEY_PRESS:
		{
			xcb_key_press_event_t *kp = reinterpret_cast<xcb_key_press_event_t*>(event);
			done = kp->detail == 9;
		}
			break;
		case XCB_DESTROY_NOTIFY:
			done = true;
			break;
		case XCB_CLIENT_MESSAGE:
			message = reinterpret_cast<xcb_client_message_event_t*>(event);
			if (message->data.data32[0] == m_atom_wm_delete_window->atom)
			{
				done = true;
			}
			break;
		default:
			break;
		}
		std::free(event);
	}
	return done;
}

} /* namespace XCB */
