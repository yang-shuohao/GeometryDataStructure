#pragma once
#include "Circle.h"

namespace QT
{
	class Rectangle
	{
	public:
		Rectangle();
		Rectangle(int x, int y, int half_w, int half_h);
		//�жϾ����Ƿ��Բ�ཻ
		bool Container(Circle circle);
		//�жϾ��κ;����Ƿ��ཻ
		bool Intersects(Rectangle range);
		//����
		void Draw();
	public:
		//x��yΪ�������ĵ����꣬half_w��half_hΪ���ΰ���ߡ�
		int x;
		int y;
		int half_w;
		int half_h;
	};
}


