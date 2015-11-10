#include "Player.h"


Player::Player(void)
{
}
Player::Player(IControl *_iControl)
{
	iControl=_iControl;
}
Player::~Player(void)
{
}

void Player::SetShape(float _x, float _y)
{
	iControl->xShape=_x;
	iControl->yShape=_y;
}

void Player::DrawShape(RenderWindow& window)
{
	iControl->DrawShape(window);
}

void Player::Step(int coord[2][32], Figure **figure)
{
	iControl->Step(coord, figure);
}