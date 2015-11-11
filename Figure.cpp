#include "Figure.h"


Figure::Figure(void)
{
	poleShape = new bool*[8];
	for(int i=0;i<8;i++)
	{
		poleShape[i] = new bool[8];
	}
}


Figure::~Figure(void)
{
}

#pragma region SetShape
void Figure::SetBool()
{
	kShape=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			poleShape[i][j]=false;
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
bool** Figure::GetBool()
{
	return poleShape;
}
int Figure::GetKShape()
{
	return kShape;
}
#pragma endregion