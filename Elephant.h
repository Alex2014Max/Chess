#pragma once
#include "header.h"
#include "Figure.h"

class Elephant : public Figure
{
public:
	Elephant(void);
	~Elephant(void);
	
	void SetCoordsShapes(int _coord[2][32], int _index);
	void DrawShapes(RenderWindow& window);
};

