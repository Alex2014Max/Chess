#pragma once
#include "header.h"
#include "IControl.h"

class IPC : public IControl
{
public:
	IPC(void);
	~IPC(void);

	void DrawShape(RenderWindow& window);
	void Step(int coord[2][32], Figure **figure);
};

