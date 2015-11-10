#pragma once
#include "header.h"
#include "IStep.h"

class Figure : public IStep
{
	bool poleShape[8][8];
public:
	Figure(void);
	~Figure(void);

	void SetCoordsShapes(int _coord[2][32]);
	void DrawShapes(RenderWindow& window);
};

