#include "IUser.h"


IUser::IUser(void)
{
}


IUser::~IUser(void)
{
}

void IUser::DrawShape(RenderWindow& window)
{
	sShape.setPosition(xShape,yShape);
	window.draw(sShape);
	window.display();
}

void IUser::Step(int coord[2][32], Figure **figure)
{

}