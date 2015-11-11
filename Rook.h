#pragma once
#include "header.h"
#include "Figure.h"

class Rook : public Figure
{
public:
	Rook(void);
	~Rook(void);
	
	void SetCoordsShapes(int _coord[2][32], int _index);
	void DrawShapes(RenderWindow& window);
};

