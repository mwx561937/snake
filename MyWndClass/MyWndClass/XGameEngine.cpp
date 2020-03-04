#include "XGameEngine.h"


XGameEngine::XGameEngine()
{
}


XGameEngine::~XGameEngine()
{
}

void XGameEngine::GameInit()
{
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	

	m_hdc = GetDC(m_hWnd);
	m_chdc = CreateCompatibleDC(m_hdc);

	m_duration = 250;
	m_duration_bk = m_duration;
	m_duration_orgin = m_duration;
	m_movefood.LoadSnake(&m_snake);
	//m_ctxtdc = CreateCompatibleDC(m_hdc);
	//SetBkColor(m_ctxtdc, RGB(255, 255, 0));
	//m_pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	//m_brush = CreateSolidBrush(RGB(255, 255, 0));
	//SelectObject(m_chdc, m_brush);
}

bool XGameEngine::GameRun()
{
	m_input.ScanKeyState(&m_snake);
	m_snake.ResetUnreal();

	if (GetTickCount() - last_time > m_duration) {
		last_time = GetTickCount();
		m_snake.Move();
		m_input.ResetDelayFlag();
		if (m_snake.IsCrash()) {
			MessageBoxA(NULL, "游戏结束!", "提示", MB_OK);
			return false;
		}
		if (m_snake.IsEatten(&m_fastfood)) {
			GameSpeedFast();
			m_fastfood.Move();
			cout << m_snake.GetLength() << endl;
		}
		else if (m_snake.IsEatten(&m_food)) {
			GameSpeedChange();
			m_snake.SetUnreal();
			m_food.Move();
			m_isDuringFastTime = false;
			cout << m_snake.GetLength() << endl;

		}
		else if (m_snake.IsEatten(&m_movefood)) {
			m_movefood.Move();
			m_movefood.LevelUp();
			cout << m_snake.GetLength() << endl;
		}
		//else if (m_snake.IsEatten(&m_movefood)) {
		//	m_movefood.Move();
		//}
	}

	if (m_isDuringFastTime) {
		DWORD cur = GetTickCount();
		if (cur - before_fast_time > 10000) {
			m_duration = m_duration_bk;
			m_isDuringFastTime = false;
		}
	}

	//TextOutA(m_ctxtdc, 0, 0, "hello", 6);
	m_cbgbmp = CreateCompatibleBitmap(m_hdc, m_width, m_height);
	SelectObject(m_chdc, m_cbgbmp);
	//rt.DrawObject(m_chdc);


	m_snake.DrawObject(m_chdc);
	m_food.DrawObject(m_chdc);
	m_fastfood.DrawObject(m_chdc, RGB(0, 255, 0));
	m_movefood.Go();
	m_movefood.DrawObject(m_chdc, RGB(0, 255, 255));

	BitBlt(m_hdc, 0, 0, m_width, m_height - 40, m_chdc, 0, 0, SRCCOPY);
	//BitBlt(m_hdc, 0, 0, 100, 40, m_ctxtdc, 0, 0, SRCCOPY);
	DeleteObject(m_cbgbmp);
	
	return true;
}

void XGameEngine::GameEnd()
{
	ReleaseDC(m_hWnd, m_ctxtdc);
	ReleaseDC(m_hWnd, m_chdc);
	ReleaseDC(m_hWnd,m_hdc);
	FreeConsole();
}

void XGameEngine::GameSpeedChange()
{
	int snake_len = m_snake.GetLength();
	if (snake_len > 30) {
		return;
	}
	else {
		//if (snake_len % 2 == 0) {
		m_duration = m_duration_orgin - 100 * (static_cast<float>(snake_len / 20));
		m_duration_bk = m_duration;
			//cout << static_cast<float>((float)snake_len / 20) << endl;
		//}
	}

}

void XGameEngine::GameSpeedFast()
{
	//if (!m_isDuringFastTime) {
	m_isDuringFastTime = true;
	before_fast_time = GetTickCount();
	m_duration = 50;
	//}
}
