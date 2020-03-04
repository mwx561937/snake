#pragma once
#include "XObject.h"
class XRectangle :
	public XObject
{
public:
	void Move();
	XRectangle();
	~XRectangle();
	void DrawObject(void* hdc);
};

