#include "XObject.h"
#include <math.h>



XObject::XObject()
{
	m_x = 0;
	m_y = 0;
	m_vx = 20;
	m_vy = 20;
	m_wx = 20;
	m_wy = 20;
}


XObject::~XObject()
{
}

void XObject::MoveX()
{
	m_x += m_vx;
}

void XObject::MoveY()
{
	m_y += m_vy;
}

bool XObject::IsEatten(XObject* otherObj)
{
	if (abs(m_x - otherObj->m_x) < 20 && abs(m_y - otherObj->m_y) < 20)
	{
		return true;
	}
	return false;
}

