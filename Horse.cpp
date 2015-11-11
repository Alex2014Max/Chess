#include "Horse.h"


Horse::Horse(void)
{
}


Horse::~Horse(void)
{
}

void Horse::SetCoordsShapes(int _coord[2][32], int _index)
{
	SetBool();
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(((i==_coord[0][_index]-2)&&(j==_coord[1][_index]-1))||
			   ((i==_coord[0][_index]-2)&&(j==_coord[1][_index]+1))||
			   ((i==_coord[0][_index]+2)&&(j==_coord[1][_index]-1))||
			   ((i==_coord[0][_index]+2)&&(j==_coord[1][_index]+1))||
			   ((j==_coord[1][_index]-2)&&(i==_coord[1][_index]-1))||
			   ((j==_coord[1][_index]-2)&&(i==_coord[1][_index]+1))||
			   ((j==_coord[1][_index]+2)&&(i==_coord[1][_index]-1))||
			   ((j==_coord[1][_index]+2)&&(i==_coord[1][_index]+1)))
			{
				SetBool(i,j,true);
			}
		}
	}
}
void Horse::DrawShapes(RenderWindow& window)
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