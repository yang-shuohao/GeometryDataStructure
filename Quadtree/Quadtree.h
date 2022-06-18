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
		//插入圆形
		void Insert(Circle circle);
		//划分
		void Subdivide();
		//查询
		void Query(Rectangle range,std::vector<Circle>& found);
		//绘制
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