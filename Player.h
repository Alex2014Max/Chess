#pragma once
#include "header.h"
#include "IControl.h"
#include "IUser.h"
#include "IPC.h"

class Player
{
	IControl *iControl;
public:
	Player(void);
	Player(IControl *_iControl);
	~Player(void);

	void SetShape(float _x, float _y);
	void DrawShape(RenderWindow& window);
	void Step(int coord[2][32], Figure **figure);
};

