#include "header.h"
#include "Game.h"

int main()
{
	setlocale(LC_ALL,"Russian");
	srand(time(NULL));

	RenderWindow window(VideoMode(720, 720), "Chess");

	Clock clock;

	Game game;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 8000;

		Vector2i pos=Mouse::getPosition(window);
		//cout << pixelPos.x << "\t" << pixelPos.y << "\n";

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if(event.type==Event::KeyPressed)
			{
				if(event.key.code==Keyboard::Escape)
				{
					game.SetMenu();
				}
			}
			if(event.type==Event::MouseButtonPressed)
			{
				if(event.key.code==Mouse::Left)
				{
					game.MBPressed(0,window);
				}
			}
		}
		
		window.clear();
		game.GameMenu(window);
		game.DrawPole(window,game.stepI);
		window.display();
	}

	return 0;
}