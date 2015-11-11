#pragma once
#include "header.h"
#include "IStep.h"

class Figure : public IStep
{
	bool** poleShape;
	int kShape;
public:
	Figure(void);
	~Figure(void);

#pragma region SetShape
	virtual void SetCoordsShapes(int _coord[2][32], int _index)=0;
	virtual void DrawShapes(RenderWindow& window)=0;
	void SetBool();
	void SetBool(int _i, int _j, bool _p);
	bool** GetBool();
	int GetKShape();
#pragma endregion
};

