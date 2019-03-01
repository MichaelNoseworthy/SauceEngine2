#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Components/HardwareChecks.cpp"
#include "resource.h"
#include "Components/GameObject.h"
#include "SceneManager.h"
#include "Scenes.hpp"
#include <SFML/Audio.hpp>

using namespace sf;


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
//int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR pArgs, INT)
int main()
{
	//sf::Music music;
	//if (!music.openFromFile("../../Assets/Music/metroid03.ogg"))
	//	return -1; // error

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && isPlau)
	//{
	//	music.play();
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard:P))
	//{
	//	music.stop();
	//}
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

				//cin.get();
				//Applications variables
				std::vector<SceneManager*> Scenes;
				int scene = 0;

				//Window creation
				sf::RenderWindow App(sf::VideoMode(640, 480, 32), "Sauce Engine 2");

				//Mouse cursor no more visible
				App.setMouseCursorVisible(false);

				//Screens preparations
				scene_0 s0;
				Scenes.push_back(&s0);
				scene_1 s1;
				Scenes.push_back(&s1);

				//Main loop
				while (scene >= 0)
				{
					scene = Scenes[scene]->Run(App);
				}
				//system("PAUSE");  //Enable me for debugging purposes.  Must be using console window.
				return EXIT_SUCCESS;

				/*

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
				windowClass.lpszClassName = TEXT("SauceEngine2");
				RegisterClass(&windowClass);


				// Let's create the main window
				HWND window = CreateWindow(TEXT("SauceEngine2"), TEXT("Sauce Engine 2"), WS_SYSMENU | WS_VISIBLE, 200, 200, 660, 520, NULL, NULL, instance, NULL);

				// Add a button for exiting
				button = CreateWindow(TEXT("BUTTON"), TEXT("Quit"), WS_CHILD | WS_VISIBLE, 560, 440, 80, 40, window, NULL, instance, NULL);
				sf::Clock clock;

				sf::Texture SplashScreenImage;
				if (!SplashScreenImage.loadFromFile("../../Assets/images/SplashScreen.jpg") || !SplashScreenImage.loadFromFile("../../Assets/images/SplashScreen.jpg"))
				{
					//find it in the game directory instead
					if (!SplashScreenImage.loadFromFile("./Assets/images/SplashScreen.jpg") || !SplashScreenImage.loadFromFile("./Assets/images/SplashScreen.jpg"))
						return EXIT_FAILURE; //can't find it at all
				}

				sf::Sprite SplashSprite(SplashScreenImage);
				SplashSprite.setOrigin(sf::Vector2f(SplashScreenImage.getSize()) / 2.f);
				SplashSprite.setPosition(SplashSprite.getOrigin());


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
						SplashScreen.draw(SplashSprite);
						SplashScreen.display();
					}
				}
				// Let's create two SFML views
				HWND view1 = CreateWindow(TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, 20, 20, 300, 400, window, NULL, instance, NULL);
				HWND view2 = CreateWindow(TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, 340, 20, 300, 400, window, NULL, instance, NULL);
				HWND view3 = CreateWindow(TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS, 0, 0, 660, 520, window, NULL, instance, NULL);
				sf::RenderWindow SFMLView1(view1);
				sf::RenderWindow SFMLView2(view2);
				sf::RenderWindow SFMLView3(view3);

				SFMLView3.setVisible(false);

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
				//
				//window.setFramerateLimit(30);

				sf::RectangleShape test(sf::Vector2f (100.0f, 100.0f));
				test.setFillColor(sf::Color::Red);

				// Loop until a WM_QUIT message is received
				MSG message;
				message.message = static_cast<UINT>(~WM_QUIT);
				while (message.message != WM_QUIT)
				{
					if (Mouse::isButtonPressed(Mouse::Left))
					{
					}
					if (Mouse::isButtonPressed(Mouse::Right))
					{
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					{
						test.move(-0.1, 0.0f);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					{
						test.move(0.1, 0.0f);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						test.move(0.0, -0.1f);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						test.move(0.0, 0.1f);
					}

					
						  
					/*if (event.type == sf::Event::EventType::KeyPressed) {
						if (event.key.code == sf::Keyboard::Left) {
							printf("left");
						}
					}
					

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
						bool isStarted = false;
						if (elapsed1 >= sf::seconds(5.0f))
						{
							SFMLView1.setVisible(false);
							SFMLView2.setVisible(false);
							SFMLView3.setVisible(true);
							//SFMLView3.clear(sf::Color::Green);
							SFMLView3.draw(aTest.sprite);
							SFMLView1.close();
							SFMLView2.close();
							if (elapsed1 >= sf::seconds(5.0f))
							{
								aTest.SetPosition(aTest.GetPositionX() + 1, 0);
								elapsed1 = clock.restart();
								isStarted = true;
							}

							if (isStarted)
							{
								if (elapsed1 >= sf::seconds(1.0f))
								{
									aTest.SetPosition(aTest.GetPositionX() + 10, aTest.GetPositionY() + 10);
									elapsed1 = clock.restart();
								}
							}
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
						SFMLView3.clear();
						SFMLView3.draw(test);
						SFMLView1.display();
						SFMLView2.display();
						SFMLView3.display();
	
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
				



				// Destroy the main window (all its child controls will be destroyed)
				DestroyWindow(window);

				// Don't forget to unregister the window class
				UnregisterClass(TEXT("SauceEngine2"), instance);

				return EXIT_SUCCESS;
				*/

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


