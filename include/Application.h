#pragma once
#include <windows.h>

#include "Straight.h"
#include "Window.h"
#include "Renderer.h"

namespace Straight
{
	class STRAIGHT_API Application final
	{
	public:
		Application(HINSTANCE hInstance);
		~Application();
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		bool Initialize();
		void Run();
		void Dispose();

		Window* GetWindow() { return m_window.get(); }
		Renderer* GetRenderer() { return m_renderer.get(); }
		HINSTANCE GetHInstance() const { return m_hInstance; }

	private:
		UPtr<Window> m_window;
		UPtr<Renderer> m_renderer;

		HINSTANCE m_hInstance;
	};
}