#include "Menu.h"

Menu::Menu()
{
	pMenu=true;
	pContinue=true;
	multiplicity=0;
	
	tMenu.loadFromFile("images/menu.png");
	tMenuSettings.loadFromFile("images/menu_settings.png");
	sMenu.setTexture(tMenu);
	sMenuSettings.setTexture(tMenuSettings);
	sMenu.setPosition(210,160);
	sMenuSettings.setPosition(210,210);
}
Menu::~Menu()
{
	
}

bool Menu::MBPressed(double x,double y,double w,double h,RenderWindow& window)
{
	Vector2i pos=Mouse::getPosition(window);
	//cout << pos.x << "\t" << pos.y << "\n";
	if(pos.x>=x&&pos.x<=x+w-1&&pos.y>=y&&pos.y<=y+h-1)
	{
		cout << "Is Clicked to Object ";
		return true;
	}
	else
	{
		return false;
	}
}

void Menu::BMenu(RenderWindow& window)
{
	bool pDoWhile=true;
	do
	{
		window.clear();
		window.draw(sMenu);
		window.display();
		Event event;
		while (window.pollEvent(event))
		{
			if(event.type==Event::MouseButtonPressed)
			{
				if(event.key.code==Mouse::Left)
				{
					if(MBPressed(210,160,300,100,window))
					{
						BContinue();
						cout << "Continue\n";
						pDoWhile=false;
					}
					if(MBPressed(210,260,300,100,window))
					{
						BNewGame();
						cout << "NewGame\n";
						pDoWhile=false;
					}
					if(MBPressed(210,360,300,100,window))
					{
						BSettings(window);
						cout << "Settings\n";
						pDoWhile=false;
					}
					if(MBPressed(210,460,300,100,window))
					{
						BExit(window);
						cout << "Exit\n";
						pDoWhile=false;
					}
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
	}while(pDoWhile);
}

void Menu::BContinue()
{
	pGame=true;
	pMenu=false;
}

void Menu::BNewGame()
{
	pGame=false;
	pMenu=false;
}

void Menu::BSettings(RenderWindow& window)
{
	bool pDoWhile=true;
	do
	{
		window.clear();
		window.draw(sMenuSettings);
		window.display();
		Event event;
		while (window.pollEvent(event))
		{
			if(event.type==Event::MouseButtonPressed)
			{
				if(event.key.code==Mouse::Left)
				{
					if(MBPressed(210,210,300,100,window))
					{
						BEasy();
						cout << "Easy\n";
						pDoWhile=false;
					}
					if(MBPressed(210,310,300,100,window))
					{
						BMedium();
						cout << "Medium\n";
						pDoWhile=false;
					}
					if(MBPressed(210,410,300,100,window))
					{
						BHard();
						cout << "Hard\n";
						pDoWhile=false;
					}
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
	}while(pDoWhile);

	BMenu(window);
}

void Menu::BExit(RenderWindow& window)
{
	window.close();
}

void Menu::BEasy()
{
	multiplicity=0;
}

void Menu::BMedium()
{
	multiplicity=1;
}

void Menu::BHard()
{
	multiplicity=2;
}