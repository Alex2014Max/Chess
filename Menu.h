#pragma once
#include "header.h"

class Menu
{
	Texture tMenu;
	Texture tMenuSettings;
	Sprite sMenu;
	Sprite sMenuSettings;
	
public:
	bool pContinue;
	bool pMenu;
	bool pGame;
	int multiplicity;
	
	Menu(void);
	~Menu(void);
	
	static bool MBPressed(double,double,double,double,RenderWindow& window);
	
	void BMenu(RenderWindow& window);
	void BContinue();
	void BNewGame();
	void BSettings(RenderWindow& window);
	void BEasy();
	void BMedium();
	void BHard();
	void BExit(RenderWindow& window);
	
};