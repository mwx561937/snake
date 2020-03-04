// MyWndClass.cpp : 定义应用程序的入口点。
//
#include "XGameEngine.h"



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	XGameEngine me;
	me.DoWork(hInstance,640,500);
	return 0;
}
