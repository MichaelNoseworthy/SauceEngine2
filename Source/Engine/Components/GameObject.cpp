#include "GameObject.h"


GameObject::GameObject()
{	
	name = "DefaultGameObject";
	SetPosition(0, 0);
}

GameObject::GameObject(string n, float x, float y)
{
	name = n;
	SetPosition(x, y);
}

GameObject::GameObject(string n, sf::Vector2f position)
{
	name = n;
	SetPosition(position);
}

void GameObject::SetParent(GameObject* p)
{
	parent = p;
}

void GameObject::AddChild(GameObject* s)
{
	children.push_back(s);
	s->parent = this;
}


GameObject::~GameObject()
{
	for (unsigned int i = 0; i < children.size(); i++)
		delete children[i];
}

void GameObject::SetPosition(sf::Vector2f position)
{
	xPosition = position.x;
	yPosition = position.y;

	//if (&sprite.getTexture)
		sprite.setPosition(xPosition, yPosition);
}

void GameObject::SetPosition(float x,float y)
{
	xPosition = x;
	yPosition = y;

	//if (&sprite.getTexture)
		sprite.setPosition(xPosition, yPosition);
}

float GameObject::GetPositionX()
{
	return xPosition;
}

float GameObject::GetPositionY()
{
	return yPosition;
}


sf::Vector2f GameObject::GetPosition(GameObject* o){
	sf::Vector2f position(o->xPosition, o->yPosition);	
	
	return position;
}
