#pragma once
#include "header.h"
#include "Player.h"
#include "Pawn.h"
#include "Rook.h"
#include "Horse.h"
#include "Elephant.h"
#include "Queen.h"
#include "King.h"
#include "Menu.h"

class Game
{
	bool k;
	int coord[2][32];

	IControl *iControl[2];
	Player *player[2];
	Figure *figure[6];
	Sprite sFig[32];
	Texture tFig;
	Sprite sTable;
	Texture tTable;
	float xTable,yTable;
	int sumBL;

	//menu
	Menu menu;
	ifstream fin;
	ofstream fout;
public:
	int stepI;

	Game(void);
	~Game(void);

#pragma region menu
	void SetMenu();
	void GameMenu(RenderWindow& window);
#pragma endregion
#pragma region table
	void SetFigure();
	void SetFig();
	void SetTable();
	void SetCoords(bool _p);
	void SetPole();
	void DrawPole(RenderWindow& window, int _i);
#pragma endregion
#pragma region step
	void Step(bool _step);
	void MBPressed(bool _step,RenderWindow& window);
#pragma endregion
};

