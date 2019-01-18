#include "GameObject.h"


GameObject::GameObject()
{
	name = "DefaultGameObject";
	position(0, 0);
}

GameObject::GameObject(string n, int x, int y)
{
	name = n;
	position(x, y);
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
