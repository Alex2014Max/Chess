#pragma once
#include "header.h"
#include "Figure.h"

class Horse : public Figure
{
public:
	Horse(void);
	~Horse(void);
	
	void SetCoordsShapes(int _coord[2][32], int _index);
	void DrawShapes(RenderWindow& window);
};

