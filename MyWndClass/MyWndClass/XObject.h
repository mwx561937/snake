#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
enum OBJ_DIRECTION {
	MOV_LEFT,
	MOV_RIGHT,
	MOV_UP,
	MOV_DOWN
};




class XObject
{
public:
	XObject();
	~XObject();

	virtual void MoveX();
	virtual void MoveY();

	virtual void DrawObject(void*) = 0;
	virtual void Move() = 0;
	virtual bool IsEatten(XObject* );


public:
	int m_x;
	int m_y;
	int m_vx;
	int m_vy;
	int m_wx;
	int m_wy;
	OBJ_DIRECTION m_dir;
};

