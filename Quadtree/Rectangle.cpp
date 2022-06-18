#include "Rectangle.h"
#include <graphics.h>

namespace QT
{
	Rectangle::Rectangle()
	{
		x = 0;
		y = 0;
		half_w = 0;
		half_h = 0;
	}

	Rectangle::Rectangle(int x, int y, int half_w, int half_h)
	{
		this->x = x;
		this->y = y;
		this->half_w = half_w;
		this->half_h = half_h;
	}

	bool Rectangle::Container(Circle circle)
	{
		return !(circle.x - circle.r > x + half_w || circle.x + circle.r < x - half_w
			|| circle.y - circle.r > y + half_h || circle.y + circle.r < y - half_h);
	}

	bool Rectangle::Intersects(Rectangle range)
	{
		return !(range.x - range.half_w > x + half_w || range.x + range.half_w < x - half_w
			|| range.y - range.half_h > y + half_h || range.y + range.half_h < y - half_h);
	}

	void Rectangle::Draw()
	{
		rectangle(x - half_w, y - half_h, x + half_w, y + half_h);
	}
}