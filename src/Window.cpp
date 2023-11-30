#include "Window.h"
#include "Application.h"

namespace
{
	const char* APPLICATION_NAME = "Straight";

	LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
	{
		Straight::Application* app = (Straight::Application*)GetWindowLongPtr(hwnd, 0);

		switch (umessage)
		{
			case WM_DESTROY: PostQuitMessage(0); return 0;
			case WM_CLOSE: PostQuitMessage(0); return 0;

		default:
			return DefWindowProcA(hwnd, umessage, wparam, lparam);
		}
	}

}

namespace Straight
{
	Window::Window(Application* owner) :
		m_hwnd(0),
		m_owner(owner)
	{}
	
	Window::~Window()
	{}

	bool Window::Initialize(int width, int height)
	{
		WNDCLASSEX wc{};
		DEVMODE dmScreenSettings{};
		int posX = 0;
		int posY = 0;

		HINSTANCE hInstance = m_owner->GetHInstance();

		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = sizeof(m_owner);
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hIconSm = wc.hIcon;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wc.lpszMenuName = NULL;
		wc.lpszClassName = APPLICATION_NAME;
		wc.cbSize = sizeof(WNDCLASSEX);
		
		RegisterClassEx(&wc);

		posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;

		m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, APPLICATION_NAME, APPLICATION_NAME,
			WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
			posX, posY, width, height, NULL, NULL, hInstance, NULL);

		SetWindowLongPtr(m_hwnd, 0, (LONG_PTR)m_owner);

		ShowWindow(m_hwnd, SW_SHOW);
		SetForegroundWindow(m_hwnd);
		SetFocus(m_hwnd);

		return true;
	}

}