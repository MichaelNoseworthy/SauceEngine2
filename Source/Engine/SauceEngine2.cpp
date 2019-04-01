/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "sol.hpp"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Components/HardwareChecks.cpp"
#include "resource.h"
#include "SceneManager.h"
#include "Scenes.hpp"
//#include "AssetManager.h"
#include "Assets.cpp"
#pragma comment( lib, "Lua" )

//static AssetManager Assets;

HWND button;
sf::Event event;
////////////////////////////////////////////////////////////
/// Function called whenever one of our windows receives a message
///
////////////////////////////////////////////////////////////
LRESULT CALLBACK onEvent(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// Quit when we close the main window
		case WM_CLOSE:
		{
			PostQuitMessage(0);
			return 0;
		}

		// Quit when we click the "quit" button
		case WM_COMMAND:
		{
			if (reinterpret_cast<HWND>(lParam) == button)
			{
				PostQuitMessage(0);
				return 0;
			}
		}
	}
	return DefWindowProc(handle, message, wParam, lParam);
}

//If you wish to only display the game window and not the console, use WINAPI instead
int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR pArgs, INT)
//int main()
{
	HANDLE ghMutex;
	ghMutex = CreateMutex(NULL,
		FALSE, L"SauceEngine2");

	DWORD err = GetLastError();
	LPTSTR Error = 0;
	LPCTSTR Opened = L"Error, close it";
	if (ghMutex == NULL)
	{

		if (::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			err,
			0,
			(LPTSTR)&Error,
			0,
			NULL) == 0)
			{
				// Failed in translating message
			const std::wstring eMsg = L"\n\nException caught at main ghMutex window creation.";
			MessageBox(nullptr, eMsg.c_str(), L"Unhandled STL Exception at ghMutex", MB_OK);
			}
		return 1;
	}

	DWORD result = WaitForSingleObject(ghMutex, 0);

	if (result == WAIT_OBJECT_0)
	{
		try
		{
			CheckRAM();
			CheckCPU();
			int hardwareResult;
			hardwareResult = CheckHDDHardware();
			if (hardwareResult == 0)
				return 1;
			else
			{
				// Loop until a WM_QUIT message is received
				MSG message;
				message.message = static_cast<UINT>(~WM_QUIT);

				while (message.message != WM_QUIT)
				{
					if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
					{
						// If a message was waiting in the message queue, process it
						TranslateMessage(&message);
						DispatchMessage(&message);
					}
					else
					{
						/* Test lua
						sol::state lua;

						lua["message"] = [](const std::string& msg) {
							MessageBoxA(nullptr, msg.c_str(), "Lua Message", MB_OK);
						};
						lua.do_string("message('Howdy, from Lua!')");
						*/
						
						//loadAssetResources();


						beginGame();
						//system("PAUSE");  //Enable me for debugging purposes.  Must be using console window.
						return EXIT_SUCCESS; //Program ended properly
					}
				}
				return EXIT_SUCCESS; //Should never be reached
			}
		}
		catch (const std::exception& e)
		{
			// need to convert std::exception what() string from narrow to wide string
			const std::string whatStr(e.what());
			const std::wstring eMsg = std::wstring(whatStr.begin(), whatStr.end()) +
				L"\n\nException caught at main window creation.";
			MessageBox(nullptr, eMsg.c_str(), L"Unhandled STL Exception", MB_OK);
		}
		
	}
	else
	{
		std::string outmsg = "CreateMutex error\nDo not open multiple applications of Sauce Engine 2";
		OutputDebugStringA(outmsg.c_str());
		cout << "Sauce Engine is already opened." << endl; //shows only in console
		MessageBox(NULL, L"CreateMutex error\n" L"Do not open multiple applications of Sauce Engine 2", Opened, MB_OK | MB_ICONWARNING); //Pops up an error message
		return 1;
	}

	return EXIT_SUCCESS; //Should never be reached
}
