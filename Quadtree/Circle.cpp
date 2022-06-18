#include "Circle.h"
#include <graphics.h>

namespace QT
{
	Circle::Circle(int x, int y, int r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}

	void Circle::Draw()
	{
		circle(x, y, r);
	}
}