#pragma once

#ifndef Sauce_hpp
#define Sauce_hpp

//Basic Scene Class
#include "SceneManager.h"
#include <windows.h>
//#include "SceneLoader.h"
#include <SFML/Graphics.hpp>
#include "Components/HardwareChecks.cpp"
#include "sol.hpp"



static int lastscene = 2;

class Sauce
{

public:
	static void Initialize();
	static void Start();
};

#endif /* Sauce_hpp */