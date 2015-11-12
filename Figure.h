#pragma once
#include "header.h"
#include "IStep.h"

class Figure : public IStep
{
	bool** poleShape;
	bool** poleShapeColor;
	int kShape;
public:
	Figure(void);
	~Figure(void);

#pragma region SetShape
	virtual void SetCoordsShapes(int _coord[2][32], int _index)=0;
	virtual void DrawShapes(RenderWindow& window)=0;
	void SetBoolAndColor();
	void SetBool(int _i, int _j, bool _p);
	void SetColor(int _i, int _j, bool _p);
	bool** GetBool();
	bool** GetColor();
	int GetKShape();
	bool ExistenceWhite(int _coord[2][32], int _x, int _y);
	bool ExistenceBlack(int _coord[2][32], int _x, int _y);
#pragma endregion
};

