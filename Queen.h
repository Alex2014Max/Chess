#pragma once
#include "header.h"
#include "Figure.h"

class Queen : public Figure
{
public:
	Queen(void);
	~Queen(void);
	
	void SetCoordsShapes(int _coord[2][32], int _index);
	void DrawShapes(RenderWindow& window);
};

