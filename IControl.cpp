#include "IControl.h"


IControl::IControl(void)
{
	tShape.loadFromFile("images/shape_texture.png");
	sShape.setTexture(tShape);
	sShape.setColor(Color::Black);
}


IControl::~IControl(void)
{
}

void IControl::DrawShape(RenderWindow& window)
{
	sShape.setPosition(xShape,yShape);
	window.draw(sShape);
	window.display();
}