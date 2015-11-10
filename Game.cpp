#include "Game.h"

Game::Game(void)
{
	k=true;
	stepI=0;
	iControl[0]=new IUser;
	iControl[1]=new IPC;
	player[0]=new Player(iControl[0]);
	player[1]=new Player(iControl[1]);
	SetFigure();
	SetFig();
	SetTable();
}
Game::~Game(void)
{
}

void Game::SetFigure()
{
	figure[0]=new Pawn;
	figure[1]=new Rook;
	figure[2]=new Horse;
	figure[3]=new Elephant;
	figure[4]=new Queen;
	figure[5]=new King;
}
void Game::SetFig()
{
	tFig.loadFromFile("images/chess_figure.png");
	for(int i=0;i<32;i++)
	{
		sFig[i].setTexture(tFig);
	}
#pragma region sprite figure
		sFig[0].setTextureRect(IntRect(270, 72, 54, 72));
		sFig[1].setTextureRect(IntRect(270, 72, 54, 72));
		sFig[2].setTextureRect(IntRect(270, 72, 54, 72));
		sFig[3].setTextureRect(IntRect(270, 72, 54, 72));
		sFig[4].setTextureRect(IntRect(270, 72, 54, 72));
		sFig[5].setTextureRect(IntRect(270, 72, 54, 72));
		sFig[6].setTextureRect(IntRect(270, 72, 54, 72));
		sFig[7].setTextureRect(IntRect(270, 72, 54, 72));
		sFig[8].setTextureRect(IntRect(0, 72, 54, 72));
		sFig[9].setTextureRect(IntRect(216, 72, 54, 72));
		sFig[10].setTextureRect(IntRect(54, 72, 54, 72));
		sFig[11].setTextureRect(IntRect(108, 72, 54, 72));
		sFig[12].setTextureRect(IntRect(162, 72, 54, 72));
		sFig[13].setTextureRect(IntRect(54, 72, 54, 72));
		sFig[14].setTextureRect(IntRect(216, 72, 54, 72));
		sFig[15].setTextureRect(IntRect(0, 72, 54, 72));
		sFig[16].setTextureRect(IntRect(270, 0, 54, 72));
		sFig[17].setTextureRect(IntRect(270, 0, 54, 72));
		sFig[18].setTextureRect(IntRect(270, 0, 54, 72));
		sFig[19].setTextureRect(IntRect(270, 0, 54, 72));
		sFig[20].setTextureRect(IntRect(270, 0, 54, 72));
		sFig[21].setTextureRect(IntRect(270, 0, 54, 72));
		sFig[22].setTextureRect(IntRect(270, 0, 54, 72));
		sFig[23].setTextureRect(IntRect(270, 0, 54, 72));
		sFig[24].setTextureRect(IntRect(0, 0, 54, 72));
		sFig[25].setTextureRect(IntRect(216, 0, 54, 72));
		sFig[26].setTextureRect(IntRect(54, 0, 54, 72));
		sFig[27].setTextureRect(IntRect(108, 0, 54, 72));
		sFig[28].setTextureRect(IntRect(162, 0, 54, 72));
		sFig[29].setTextureRect(IntRect(54, 0, 54, 72));
		sFig[30].setTextureRect(IntRect(216, 0, 54, 72));
		sFig[31].setTextureRect(IntRect(0, 0, 54, 72));
#pragma endregion
}
void Game::SetTable()
{
	xTable=72;
	yTable=72;
	tTable.loadFromFile("images/chess_table.png");
	sTable.setTexture(tTable);
	sTable.setPosition(xTable,yTable);
}
void Game::SetCoords(bool _p)
{
	if(!_p)
	{
		for (int i = 0; i < 32; i++)
		{
			if (i >= 0 && i < 8)
			{
				coord[1][i] = 1;
			}
			else if (i>=8&&i<16)
			{
				coord[1][i] = 0;
			}
			else if (i >= 16 && i < 24)
			{
				coord[1][i] = 6;
			}
			else
			{
				coord[1][i] = 7;
			}
			coord[0][i] = i % 8;
		}
		fout.open("resources/coords.txt");
		for (int i=0;i<32;i++)
		{
			fout << coord[0][i] << " ";
			fout << coord[1][i] << " ";
		}
		fout.close();
	}
	else
	{
		fin.open("resources/coords.txt");
		for (int i=0;i<32;i++)
		{
			fin >> coord[0][i];
			fin >> coord[1][i];
		}
		fin.close();
	}
}
void Game::SetPole()
{
	for(int i=0;i<32;i++)
	{
		sFig[i].setPosition(81+coord[0][i]*72,576-coord[1][i]*72);
	}
}

void Game::DrawPole(RenderWindow& window,int _i)
{
	window.clear();
	window.draw(sTable);
	for(int i=0;i<32;i++)
	{
		window.draw(sFig[i]);
	}
	window.display();
	if(k)
	{
		Figure fig;
		player[0]->SetShape(sFig[_i].getPosition().x-9,sFig[_i].getPosition().y);
		fig.SetCoordsShapes(coord);
		player[0]->DrawShape(window);
		fig.DrawShapes(window);
	}
	else
	{
		player[0]->SetShape(-100,-100);
	}
}

void Game::SetMenu()
{
	menu.pMenu=true;
}
void Game::GameMenu(RenderWindow& window)
{
	if(menu.pMenu)
	{
		menu.BMenu(window);
		if(menu.pGame&&!menu.pContinue)
		{
			return;
		}
		SetCoords(menu.pGame);
		SetPole();
		menu.pContinue=false;
	}
}

void Game::Step(bool _step)
{
	player[_step]->Step(coord,figure);
}
void Game::MBPressed(bool _step, RenderWindow& window)
{
	if(!_step)
	{
		for(int i=0;i<16;i++)
		{
			if(Menu::MBPressed(sFig[i].getPosition().x,sFig[i].getPosition().y,54,72,window))
			{
				stepI=i;
				break;
			}
		}
	}
}