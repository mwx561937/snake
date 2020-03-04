#include "XRectangle.h"


void XRectangle::Move()
{
	switch (m_dir)
	{
	case MOV_LEFT:
		if (m_vx > 0)
			m_vx *= -1;
		MoveX();
		break;
	case MOV_RIGHT:
		if (m_vx < 0)
			m_vx *= -1;
		MoveX();
		break;
	case MOV_UP:
		if (m_vy > 0)
			m_vy *= -1;
		MoveY();
		break;
	case MOV_DOWN:
		if (m_vy < 0)
			m_vy *= -1;
		MoveY();
		break;
	}
}

XRectangle::XRectangle()
{
	m_vx = 50;
	m_vy = 50;
}


XRectangle::~XRectangle()
{
}

void XRectangle::DrawObject(void* hdc)
{
	Rectangle((HDC)hdc, m_x, m_y, 50 + m_x, 50 + m_y);
}
