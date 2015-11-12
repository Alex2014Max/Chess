#include "Figure.h"


Figure::Figure(void)
{
	poleShape = new bool*[8];
	for(int i=0;i<8;i++)
	{
		poleShape[i] = new bool[8];
	}
	poleShapeColor = new bool*[8];
	for(int i=0;i<8;i++)
	{
		poleShapeColor[i] = new bool[8];
	}
}


Figure::~Figure(void)
{
	for(int i=0;i<8;i++)
	{
		delete [] poleShape[i];
	}
	delete [] poleShape;
	for(int i=0;i<8;i++)
	{
		delete [] poleShapeColor[i];
	}
	delete [] poleShapeColor;
}

#pragma region SetShape
void Figure::SetBoolAndColor()
{
	kShape=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			poleShape[i][j]=false;
			poleShapeColor[i][j]=false;
		}
	}
}
void Figure::SetBool(int _i, int _j, bool _p)
{
	if((_i>=0)&&(_i<8)&&(_j>=0)&&(_j<8))
	{
		poleShape[_i][_j]=_p;
		if(_p)kShape++;
	}
}
void Figure::SetColor(int _i, int _j, bool _p)
{
	if((_i>=0)&&(_i<8)&&(_j>=0)&&(_j<8))
	{
		poleShapeColor[_i][_j]=_p;
	}
}
bool** Figure::GetBool()
{
	return poleShape;
}
bool** Figure::GetColor()
{
	return poleShapeColor;
}
int Figure::GetKShape()
{
	return kShape;
}
bool Figure::ExistenceWhite(int _coord[2][32], int _x, int _y)
{
	for(int i=0;i<16;i++)
	{
		if((_x==_coord[0][i])&&(_y==_coord[1][i])) return true;
	}
	return false;
}
bool Figure::ExistenceBlack(int _coord[2][32], int _x, int _y)
{
	for(int i=16;i<32;i++)
	{
		if((_x==_coord[0][i])&&(_y==_coord[1][i])) return true;
	}
	return false;
}
#pragma endregion