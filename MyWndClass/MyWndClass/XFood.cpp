#include "XFood.h"



void XFood::DrawObject(void* h)
{
	HDC hdc = (HDC)h;
	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

	//RECT rect;
	//rect.left = m_x;
	//rect.top = m_y;
	//rect.right = m_x + m_vx;
	//rect.bottom = m_y + m_vy;

	Rectangle(hdc, m_x, m_y, m_x + m_wx, m_y + m_wy);
	//cout << m_x << ":" << m_y << endl;
	//FillRect(hdc, &rect, brush);
	SelectObject(hdc, oldbrush);
	DeleteObject(brush);
}

void XFood::DrawObject(void* h, COLORREF color)
{
	HDC hdc = (HDC)h;
	HBRUSH brush = CreateSolidBrush(color);
	HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, brush);

	//RECT rect;
	//rect.left = m_x;
	//rect.top = m_y;
	//rect.right = m_x + m_vx;
	//rect.bottom = m_y + m_vy;

	Rectangle(hdc, m_x, m_y, m_x + m_wx, m_y + m_wy);
	//cout << m_x << ":" << m_y << endl;
	//FillRect(hdc, &rect, brush);
	SelectObject(hdc, oldbrush);
	DeleteObject(brush);
}

void XFood::Move()
{
	int x = rand() % 620;
	int y = rand() % 460;

	while (x % 20 != 0)
	{
		x -= 1;
	}
	while (y % 20 != 0)
	{
		y -= 1;
	}

	m_x = x;
	m_y = y;

}

XFood::XFood()
{
	m_x = 100;
	m_y = 100;
	m_IncreaseBlock = 1;
	srand((unsigned)time(NULL));
}


XFood::~XFood()
{
}

int XFood::GetIncreateBlock()
{
	return m_IncreaseBlock;
}
