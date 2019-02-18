#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Components/HardwareChecks.cpp"
#include "resource.h"
#include "Components/GameObject.h"



HWND button;
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
//int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR pArgs, INT)
int main()
{
	HANDLE ghMutex;
	ghMutex = CreateMutex(NULL,
		FALSE, L"SauceEngine");

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

				HINSTANCE instance = GetModuleHandle(NULL);

				// Define a class for our main window
				WNDCLASS windowClass;
				windowClass.style = 0;
				windowClass.lpfnWndProc = &onEvent;
				windowClass.cbClsExtra = 0;
				windowClass.cbWndExtra = 0;
				windowClass.hInstance = instance;
				windowClass.hIcon = (HICON)LoadImage(NULL, L"Sauce.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);  //Does nothing when enabled
				windowClass.hCursor = 0;
				windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BACKGROUND);
				windowClass.lpszMenuName = NULL;
				windowClass.lpszClassName = TEXT("SFML App");
				RegisterClass(&windowClass);


				// Let's create the main window
				HWND window = CreateWindow(TEXT("SFML App"), TEXT("Sauce Engine 2"), WS_SYSMENU | WS_VISIBLE, 200, 200, 660, 520, NULL, NULL, instance, NULL);
				// Add a button for exiting
				button = CreateWindow(TEXT("BUTTON"), TEXT("Quit"), WS_CHILD | WS_VISIBLE, 560, 440, 80, 40, window, NULL, instance, NULL);
				sf::Clock clock;

				sf::RenderWindow SplashScreen(window);
				while (true)
				{
					sf::Time elapsed1 = clock.getElapsedTime();
					if (elapsed1 >= sf::seconds(3.0f))
					{
						break;
					}
					else 
					{
						SplashScreen.clear(sf::Color::Blue);
						SplashScreen.display();
					}
				}
				// Let's create two SFML views
				HWND view1 = CreateWindow(TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, 20, 20, 300, 400, window, NULL, instance, NULL);
				HWND view2 = CreateWindow(TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, 340, 20, 300, 400, window, NULL, instance, NULL);
				sf::RenderWindow SFMLView1(view1);
				sf::RenderWindow SFMLView2(view2);

				// Load some textures to display
				sf::Texture texture1, texture2, texture3;
				//find it in the main assets directory
				if (!texture1.loadFromFile("../../Assets/images/image1.jpg") || !texture2.loadFromFile("../../Assets/images/image2.jpg"))
				{
					//find it in the game directory instead
					if (!texture1.loadFromFile("./Assets/images/image1.jpg") || !texture2.loadFromFile("./Assets/images/image2.jpg"))
						return EXIT_FAILURE; //can't find it at all
				}

				if (!texture3.loadFromFile("../../Assets/images/GameObject.jpg"))
				{
					if (!texture1.loadFromFile("./Assets/images/GameObject.jpg"))
						return EXIT_FAILURE; //can't find it at all
				}

				sf::Sprite sprite1(texture1);
				sf::Sprite sprite2(texture2);
				sprite1.setOrigin(sf::Vector2f(texture1.getSize()) / 2.f);
				sprite1.setPosition(sprite1.getOrigin());

				//gameobject testing
				GameObject aTest;
				aTest.sprite.setTexture(texture3);
				aTest.SetPosition(sf::Vector2f(10, 10));

				/*
				sf::RenderWindow window({ 1024, 740 }, "Sauce Engine 2");
				*/
				//window.setFramerateLimit(30);

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
						float time = clock.getElapsedTime().asSeconds();

						// Clear views
						SFMLView1.clear();
						SFMLView2.clear();
						sf::Time elapsed1 = clock.getElapsedTime();
						//testing clock

						if (elapsed1 >= sf::seconds(5.0f))
						{
							SFMLView1.draw(aTest.sprite);
							if (elapsed1 >= sf::seconds(4.0f))
								aTest.SetPosition(0,0);
						}
						else
						{
							// Draw sprite 1 on view 1
							sprite1.setRotation(time * 100);
							SFMLView1.draw(sprite1);

							// Draw sprite 2 on view 2
							sprite2.setPosition(std::cos(time) * 100.f, 0.f);
							SFMLView2.draw(sprite2);
						}
						
						// Display each view on screen
						SFMLView1.display();
						SFMLView2.display();
	
					}
				}

				/*
				while (window.isOpen())
				{

					sf::Event event;
					while (window.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
							window.close();

					}
					sf::Time elapsed1 = clock.getElapsedTime();

					if (elapsed1 >= sf::seconds(3.0f))
					{
						background.create(1024, 740, sf::Color::Black);
						texture.loadFromImage(background);
						window.draw(sprite);
					}
					window.clear();
					window.draw(sprite);
					window.display();

				}
				*/



				// Destroy the main window (all its child controls will be destroyed)
				DestroyWindow(window);

				// Don't forget to unregister the window class
				UnregisterClass(TEXT("SFML App"), instance);

				return EXIT_SUCCESS;
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
	return 0;
}


