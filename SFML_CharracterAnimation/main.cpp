#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow win{ sf::VideoMode(800, 600), "Window" };
	sf::Texture pers1;
	sf::Sprite CharacterSprite;
	sf::IntRect textureRect(0, 0, 200, 400);
	sf::Clock clock;

	if (!(pers1.loadFromFile("Textures/Pers1Animated.png")))
	{
		std::cerr << "Error loading pers1\n";
	}

	CharacterSprite.setTexture(pers1);
	CharacterSprite.setPosition(300.f, 100.f);
	CharacterSprite.setTextureRect(textureRect);

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			//events
			if (event.type == sf::Event::Closed)
				win.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					win.close();
			}

		}

		//animation
		if (clock.getElapsedTime().asSeconds() > 1.0f)
		{
			if (textureRect.left == 600)
				textureRect.left = 0;
			else
				textureRect.left += 200;
			
			CharacterSprite.setTextureRect(textureRect);
			clock.restart();
		}

		win.clear(sf::Color::Black);
		//draw
		win.draw(CharacterSprite);
		win.display();

	}

	return 0;
}