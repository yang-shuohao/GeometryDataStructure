#pragma once
#include "Circle.h"

namespace QT
{
	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(int x, int y, int half_w, int half_h);
		//判断矩形是否和圆相交
		bool Container(Circle circle);
		//判断矩形和矩形是否相交
		bool Intersects(Rectangle range);
		//绘制
		void Draw();
	public:
		//x和y为矩形中心点坐标，half_w和half_h为矩形半宽半高。
		int x;
		int y;
		int half_w;
		int half_h;
	};
}


