#include <windows.h>

#include<iostream>
#include<sstream>
#include<exception>

#include "Application.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	try
	{
		Straight::Application application{hInstance};
		bool result = application.Initialize();

		if (!result) return 1;

		application.Run();

	}
	catch (const std::exception& e)
	{
		std::stringstream sStream{};
		sStream << "[EXCEPTION]: " << e.what() << std::endl;
		MessageBoxA(nullptr, sStream.str().c_str(), "Error", MB_OK | MB_ICONERROR);
	}

	return 0;
}