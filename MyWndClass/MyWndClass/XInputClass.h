#pragma once
#include "XObject.h"
class XInputClass
{
public:
	XInputClass();
	~XInputClass();

	void ScanKeyState(XObject* obj);
	void ResetDelayFlag();
private:
	bool KeyDelayed = false;

};

