#include "XWndClass.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

XWndClass::XWndClass()
{
}


void XWndClass::Init(HINSTANCE hInstance, DWORD width, DWORD hight)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"MyClass";
	wcex.hIconSm = NULL;

	RegisterClassExW(&wcex);


	HWND hWnd = CreateWindowW(L"MyClass", L"Game", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, width, hight, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return ;
	}

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	m_hInst = hInstance;
	m_hWnd = hWnd;
	m_width = width;
	m_height = hight;


}

void XWndClass::Run()
{
	GameInit();
	MSG msg;
	while (true)
	{
		if(PeekMessageW(&msg,nullptr,0,0,PM_REMOVE))
		{
			if (msg.message == WM_QUIT)break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (!GameRun()) {
			break;
		}
	}
}

void XWndClass::Destroy()
{
	GameEnd();
}

XWndClass::~XWndClass()
{
}


void XWndClass::DoWork(HINSTANCE hInst,DWORD width,DWORD height)
{
	Init(hInst, width, height);
	Run();
	Destroy();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

