#include <windows.h>

#include<iostream>
#include<sstream>
#include<exception>

#include "Renderer.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	try
	{
		Straight::Renderer renderer{};
	}
	catch (const std::exception& e)
	{
		std::stringstream sStream{};
		sStream << "[EXCEPTION]: " << e.what() << std::endl;
		MessageBoxA(nullptr, sStream.str().c_str(), "Error", MB_OK | MB_ICONERROR);
	}

	return 0;
}