#pragma once
#include "Rectangle.h"
#include <vector>
#include <memory>

namespace QT
{
	class QuatTree
	{
	public:
		QuatTree(Rectangle boundary, int capacity);
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
		std::unique_ptr<QuatTree> northeast;
		std::unique_ptr<QuatTree> northwest;
		std::unique_ptr<QuatTree> southeast;
		std::unique_ptr<QuatTree> southwest;
	};
}