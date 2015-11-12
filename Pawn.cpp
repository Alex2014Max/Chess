#include "Pawn.h"


Pawn::Pawn(void)
{
}


Pawn::~Pawn(void)
{
}

void Pawn::SetCoordsShapes(int _coord[2][32], int _index)
{
	SetBoolAndColor();
	SetBool(_coord[0][_index],_coord[1][_index]+1,!ExistenceBlack(_coord,_coord[0][_index],_coord[1][_index]+1));
	if(_coord[1][_index]==1)
	{
		SetBool(_coord[0][_index],_coord[1][_index]+2,!ExistenceBlack(_coord,_coord[0][_index],_coord[1][_index]+2));
	}
	if(ExistenceBlack(_coord, _coord[0][_index]-1, _coord[1][_index]+1))
	{
		SetBool(_coord[0][_index]-1,_coord[1][_index]+1,true);
		SetColor(_coord[0][_index]-1,_coord[1][_index]+1,true);
	}
	if(ExistenceBlack(_coord, _coord[0][_index]+1, _coord[1][_index]+1))
	{
		SetBool(_coord[0][_index]+1,_coord[1][_index]+1,true);
		SetColor(_coord[0][_index]+1,_coord[1][_index]+1,true);
	}
}
void Pawn::DrawShapes(RenderWindow& window)
{
	Texture tShape;
	Sprite* sShape = new Sprite[GetKShape()];
	tShape.loadFromFile("images/shape_texture.png");
	for(int i=0;i<GetKShape();i++)
	{
		sShape[i].setTexture(tShape);
		sShape[i].setColor(Color::Green);
	}
	int k1=0,k2=GetKShape();
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(k1==k2)break;
			if(GetBool()[i][j])
			{
				sShape[k1].setPosition(72+(i*72),576-(j*72));
				if(!GetColor()[i][j]) sShape[k1].setColor(Color::Blue);
				if(GetColor()[i][j]) sShape[k1].setColor(Color::Red);
				//cout << k1 << ". " << sShape[k1].getPosition().x << "\t" << sShape[k1].getPosition().y << "\n";
				k1++;
			}
		}
		if(k1==k2)break;
	}
	for(int i=0;i<k2;i++)
	{
		window.draw(sShape[i]);
	}
}