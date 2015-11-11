#pragma once
#include "header.h"
#include "Figure.h"

class King : public Figure
{
public:
	King(void);
	~King(void);
	
	void SetCoordsShapes(int _coord[2][32], int _index);
	void DrawShapes(RenderWindow& window);
};

