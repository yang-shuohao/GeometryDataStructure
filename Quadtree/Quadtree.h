#pragma once
#include "Rectangle.h"
#include <vector>
#include <memory>

namespace QT
{
	class Quadtree
	{
	public:
		Quadtree(Rectangle boundary, int capacity);
		//����Բ��
		void Insert(Circle circle);
		//����
		void Subdivide();
		//��ѯ
		void Query(Rectangle range,std::vector<Circle>& found);
		//����
		void Draw();

	public:
		Rectangle boundary;
		int capacity;
		std::vector<Circle> circles;
		bool divided;
		std::unique_ptr<Quadtree> northeast;
		std::unique_ptr<Quadtree> northwest;
		std::unique_ptr<Quadtree> southeast;
		std::unique_ptr<Quadtree> southwest;
	};
}