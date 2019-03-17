#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "Components/GameObject.h"

class Platform :public GameObject
{
public:
	Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);;
	Platform::~Platform();

	Collider GetCollider() { return Collider(body); }

	void Platform::Draw(sf::RenderWindow & window);
private:
	sf::RectangleShape body;
};

