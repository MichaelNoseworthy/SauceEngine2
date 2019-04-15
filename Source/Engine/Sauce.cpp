/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "Sauce.hpp"

//Including each screen of application
#include "scene_0.hpp"
#include "scene_1.hpp"
#include "scene_2.hpp"
#include "scene_3.hpp"


void Sauce::Initialize()
{
	CheckRAM();
	CheckCPU();
	int hardwareResult;
	hardwareResult = CheckHDDHardware();
	if (hardwareResult == 0)
	{
		const std::wstring eMsg = std::wstring(L"\n\nException caught at main window creation.");
		MessageBox(nullptr, eMsg.c_str(), L"Failed to pass hardware test", MB_OK);
		exit(-1);
	}

	// Test lua
	sol::state lua;

	lua["message"] = [](const std::string& msg) {
		MessageBoxA(nullptr, msg.c_str(), "Lua Message", MB_OK);
	};
	lua.do_string("message('Howdy, from Lua!')");
}

void Sauce::Start()
{
	//Window creation
	sf::RenderWindow App(sf::VideoMode(640, 480, 32), "Sauce Engine 2");

	//Mouse cursor no more visible
	App.setMouseCursorVisible(false);
	//Applications variables
	std::vector<SceneManager*> Scenes;
	int scene = 0; //Change scene start point.  Leave at 0!



	//Screens preparations - Add more scenes here
	scene_0 s0;
	Scenes.push_back(&s0);
	scene_1 s1;
	Scenes.push_back(&s1);
	scene_2 s2;
	Scenes.push_back(&s2);
	scene_3 s3;
	Scenes.push_back(&s3);

	//Main loop
	while (scene >= 0)
	{
		scene = Scenes[scene]->Run(App);
	}
}