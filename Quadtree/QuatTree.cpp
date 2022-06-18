#include "QuatTree.h"
#include <graphics.h>


namespace QT
{
	QuatTree::QuatTree(Rectangle boundary, int capacity)
	{
		this->boundary = boundary;
		this->capacity = capacity;
		this->circles = {};
		this->divided = false;
	}

	void QuatTree::Insert(Circle circle)
	{
		if (!boundary.Container(circle))
		{
			return;
		}

		if (circles.size() < capacity)
		{
			circles.push_back(circle);
		}
		else
		{
			if (!divided)
			{
				Subdivide();
			}
			northeast->Insert(circle);
			northwest->Insert(circle);
			southeast->Insert(circle);
			southwest->Insert(circle);
		}
	}

	void QuatTree::Subdivide()
	{
		float x = boundary.x;
		float y = boundary.y;
		float w = boundary.half_w;
		float h = boundary.half_h;

		Rectangle ne(x + w / 2, y - h / 2, w / 2, h / 2);
		Rectangle nw(x - w / 2, y - h / 2, w / 2, h / 2);
		Rectangle se(x + w / 2, y + h / 2, w / 2, h / 2);
		Rectangle sw(x - w / 2, y + h / 2, w / 2, h / 2);

		northeast = std::make_unique<QuatTree>(ne, capacity);
		northwest = std::make_unique<QuatTree>(nw, capacity);
		southeast = std::make_unique<QuatTree>(se, capacity);
		southwest = std::make_unique<QuatTree>(sw, capacity);

		divided = true;
	}

	void QuatTree::Query(Rectangle range, std::vector<Circle>& found)
	{
		if (!boundary.Intersects(range))
		{
			return;
		}
		else
		{
			for (int i=0; i < circles.size(); ++i)
			{
				if (range.Container(circles[i]))
				{
					found.push_back(circles[i]);
				}
			}
			if (divided)
			{
				northeast->Query(range, found);
				northwest->Query(range, found);
				southeast->Query(range, found);
				southwest->Query(range, found);
			}
		}
	}

	void QuatTree::Draw()
	{
		rectangle(boundary.x - boundary.half_w, boundary.y - boundary.half_h, boundary.x + boundary.half_w, boundary.y + boundary.half_h);
		if (divided)
		{
			northeast->Draw();
			northwest->Draw();
			southeast->Draw();
			southwest->Draw();
		}
	}
}