#include "IPC.h"


IPC::IPC(void)
{
}


IPC::~IPC(void)
{
}

void IPC::DrawShape(RenderWindow& window)
{
	sShape.setPosition(-100,-100);
	window.draw(sShape);
	window.display();
}


void IPC::Step(int coord[2][32], Figure **figure)
{

}