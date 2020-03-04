#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "XWndClass.h"
#include "XRectangle.h"
#include "XSnake.h"
#include "XFood.h"
#include "XMoveFood.h"
#include "XFastFood.h"
#include <stdio.h>
#include "XInputClass.h"

class XGameEngine :
	public XWndClass
{
public:
	XGameEngine();
	~XGameEngine();

private:
	void GameInit();
	bool GameRun();
	void GameEnd();

	void GameSpeedChange();
	void GameSpeedFast();

	HDC m_hdc;
	HDC m_chdc;
	HDC m_ctxtdc;
	HPEN m_pen;
	HBITMAP m_cbgbmp;
	HBRUSH m_brush;

	DWORD cur_time;
	DWORD last_time = 0;
	DWORD before_fast_time = 0;
	DWORD m_duration;
	DWORD m_duration_orgin;
	DWORD m_duration_bk;

	XSnake m_snake;
	XRectangle rt;
	XFood m_food;
	XFastFood m_fastfood;
	XMoveFood m_movefood;

	XInputClass m_input;

	bool m_isDuringFastTime = false;
};

