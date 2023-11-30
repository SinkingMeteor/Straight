#pragma once
#include <windows.h>

#include "Straight.h"

namespace Straight
{
	class Application;

	class STRAIGHT_API Window final
	{
	public:
		Window(Application* owner);
		~Window();

		bool Initialize(int width, int height);

		HWND GetHWND() const { return m_hwnd; }
	private:
		HWND m_hwnd;
		Application* m_owner;
	};
}