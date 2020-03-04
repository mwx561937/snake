#pragma once
#include "XObject.h"
#include <time.h>
class XFood :
	public XObject
{
public:
	virtual void DrawObject(void*);
	virtual void DrawObject(void*, COLORREF);
	void Move();
	XFood();
	~XFood();

	int GetIncreateBlock();
protected:
	int m_IncreaseBlock;
};

