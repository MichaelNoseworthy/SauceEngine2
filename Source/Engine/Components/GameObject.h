/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/
#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class GameObject
{
public:
	GameObject();
	GameObject(std::string name, float x, float y);
	GameObject(std::string name, sf::Vector2f position);

	int ID;
	void SetParent(GameObject* p);
	void AddChild(GameObject* s);
	sf::Vector2f GetPosition(GameObject* o);

	string name;
	
	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f position);
	float xPosition;
	float yPosition;
	bool isActive;
	string layer;
	sf::Sprite sprite;


	~GameObject();
private:
	std::vector<GameObject*> children;
	GameObject* parent;
};

