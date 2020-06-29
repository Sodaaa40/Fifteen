#include "SFML/Graphics.hpp"
#include "game.hpp"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(256, 256), "simple 15-puzzle game");

	Texture texture;
	texture.loadFromFile("./bin/images/15.png");

	int blocksize = 64;
	game fifteen;
	fifteen.shuffle();
	Sprite sprite[16];


	int n = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			sprite[n].setTexture(texture);
			sprite[n].setTextureRect(IntRect(i*blocksize, j*blocksize, blocksize, blocksize));
			n++;
		}
		
	

	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			    window.close();


			if (event.type == Event::MouseButtonPressed)
			{

				if (event.mouseButton.button == Mouse::Left)
				{
					Vector2i position = Mouse::getPosition(window);

					int vert = position.x / blocksize;
					int hor = position.y / blocksize;

					fifteen.move(fifteen.getFieldCell(hor, vert));
				}
					
			}
				
		}

		window.clear(Color::White);


		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				int num = fifteen.getFieldCell(j, i) - 1;

				sprite[num].setPosition(i*blocksize, j*blocksize);

				window.draw(sprite[num]);
			}
		


		window.display();

	}
	
	return 0;
}