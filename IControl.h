#pragma once
#include "header.h"
#include "Figure.h"

class IControl
{
	Texture tShape;
	Sprite *backLight;
public:
	Sprite sShape;
	float xShape,yShape;

	IControl(void);
	~IControl(void);

	virtual void DrawShape(RenderWindow& window)=0;
	virtual void Step(int coord[2][32], Figure **figure)=0;
};

