#pragma once
#include "XFood.h"
#include "XSnake.h"
#include <thread>

using namespace std;

class XThread {

public:
	void run();

};


class XMoveFood :
	public XFood
{
public:
	XMoveFood();
	~XMoveFood();

	void LoadSnake(XSnake*);
	void Go();
	void LevelUp();
private:
	XThread m_thread;
	DWORD m_moveTime;
	DWORD m_directTime;
	XSnake* m_snake;

	DWORD m_moveDuringTime;
};

