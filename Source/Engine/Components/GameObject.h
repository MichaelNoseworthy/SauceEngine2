/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/
#pragma once
#include <vector>
#include <string>
using namespace std;
class GameObject
{
public:
	GameObject();
	GameObject(std::string name, float x, float y);

	int ID;
	void SetParent(GameObject* p);
	void AddChild(GameObject* s);
	string name;
	int Position(float x, float y);
	int xPosition;
	int yPosition;
	bool isActive;
	string layer;

	~GameObject();
private:
	std::vector<GameObject*> children;
	GameObject* parent;
};

