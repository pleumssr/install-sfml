#include <sfml/graphics.hpp>
#include<iostream>
using namespace std;
int main()
{
	//creat the main window
	sf::RenderWindow window(sf::VideoMode(1080, 789), "sfml window");
	window.setPosition(sf::Vector2i(0, 0));
	window.setSize(sf::Vector2u(1000,600));

	//load sprite to display
	sf::Texture texture;
	texture.loadFromFile("Texture/sprite1.png");

	sf::Sprite sprite(texture);
	sprite.setPosition(500, 500);
	sprite.setTextureRect(sf::IntRect(0, 0, 116, 116));
	
	int spritemove=0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			sprite.move(-0.1f, 0.f);
			sprite.setTextureRect(sf::IntRect(spritemove*116, 116*1, 116, 116));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			sprite.move(0.1f, 0.f);
			sprite.setTextureRect(sf::IntRect(spritemove*116, 116*2, 116, 116));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			sprite.move(0.f, -0.1f);
			sprite.setTextureRect(sf::IntRect(spritemove*116, 116*3, 116, 116));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sprite.move(0.f, 0.1f);
			sprite.setTextureRect(sf::IntRect(spritemove*116, 0, 116, 116));
		}
		
		if (spritemove ==2)
		{
			spritemove = 0;
		}
		window.clear();
		window.draw(sprite);
		window.display();
		spritemove++;
	}
	return 0;
}