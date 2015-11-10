#pragma once
#include "header.h"
#include "IControl.h"

class IUser : public IControl
{
public:
	IUser(void);
	~IUser(void);

	void DrawShape(RenderWindow& window);
	void Step(int coord[2][32], Figure **figure);
};

