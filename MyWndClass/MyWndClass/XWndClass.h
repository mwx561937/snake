#pragma once
#include <Windows.h>
class XWndClass
{
public:
	XWndClass();
	~XWndClass();

	void DoWork(HINSTANCE, DWORD, DWORD);
	virtual void GameInit() = 0;
	virtual bool GameRun() = 0;
	virtual void GameEnd() = 0;



private:
	void Init(HINSTANCE,DWORD,DWORD);
	void Run();
	void Destroy();
protected:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	DWORD m_width;
	DWORD m_height;
	
};

