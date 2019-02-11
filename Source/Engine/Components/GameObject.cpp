#include "GameObject.h"


GameObject::GameObject()
{	
	name = "DefaultGameObject";
	Position(0, 0);
	
}

GameObject::GameObject(string n, float x, float y)
{
	name = n;
	Position(x, y);
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

int GameObject::Position(float x, float y)
{
	Position(x, y);
	return 0;
}

sf::Vector2f GameObject::GetPosition(GameObject* o){
	sf::Vector2f position(o->xPosition, o->yPosition);	
	
	return position;
}