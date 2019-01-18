#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window({ 1024, 740 }, "Sauce Engine 2");
	window.setFramerateLimit(30);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.clear();
		window.display();

	}
}
