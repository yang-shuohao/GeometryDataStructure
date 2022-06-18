#include <time.h>
#include <conio.h>
#include <graphics.h>

#include "QuatTree.h"
#include "Circle.h"

int width = 640;
int height = 480;

std::vector<QT::Circle> circles;
std::vector<QT::Circle> found;

int main()
{
	srand((unsigned)time(NULL));

	initgraph(width, height);

	QT::Rectangle boundary(width / 2, height / 2, width / 2, height / 2);
	QT::QuatTree qt(boundary, 4);

	setlinecolor(GREEN);
	for (int i = 0; i < 200; ++i)
	{
		QT::Circle circle(rand() % width, rand() % height, rand() % 5 + 5);
		qt.Insert(circle);
		circles.push_back(circle);
		circle.Draw();
	}
	setlinecolor(WHITE);
	qt.Draw();

	ExMessage m;

	while (true)
	{
		m = getmessage(EM_MOUSE | EM_KEY);

		switch (m.message)
		{
		case WM_MOUSEMOVE:
		{
			cleardevice();

			setlinecolor(GREEN);
			for (int i = 0; i < circles.size(); ++i)
			{
				circles[i].Draw();
			}
			setlinecolor(WHITE);
			qt.Draw();

			found.clear();

			setlinecolor(YELLOW);
			QT::Rectangle range(m.x, m.y, 50, 50);
			range.Draw();
			qt.Query(range, found);
			for (int i = 0;i < found.size();++i)
			{
				setlinecolor(RED);
				found[i].Draw();
			}
		}
		break;
		case WM_LBUTTONDOWN:
		break;

		case WM_KEYDOWN:
			if (m.vkcode == VK_ESCAPE)
				return 0;
		}
	}
	closegraph();
	return 0;
}