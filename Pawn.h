#pragma once
#include "header.h"
#include "Figure.h"

class Pawn : public Figure
{
public:
	Pawn(void);
	~Pawn(void);
	
	void SetCoordsShapes(int _coord[2][32], int _index);
	void DrawShapes(RenderWindow& window);
};

