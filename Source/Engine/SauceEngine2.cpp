#include <SFML/Graphics.hpp>
#include "Objects/HardwareChecks.cpp"

int main()
{
	sf::RenderWindow window({ 1024, 740 }, "Sauce Engine 2");
	window.setFramerateLimit(30);
	sf::Image background;
	background.create(1024, 740, sf::Color::Blue);
	sf::Texture texture;
	texture.loadFromImage(background);
	sf::Sprite sprite(texture);
	sf::Clock clock;
		CheckRAM();
		CheckCPU();
		int hardwareResult;
		hardwareResult = CheckHDDHardware();
		if (hardwareResult == 0)
			return 1;
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
}


