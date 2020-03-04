#include "XInputClass.h"



XInputClass::XInputClass()
{
}


XInputClass::~XInputClass()
{
}

void XInputClass::ScanKeyState(XObject* obj)
{
	if (!KeyDelayed) {
		if (GetAsyncKeyState(0x57) || GetAsyncKeyState(0x26)) { // w
			if (obj->m_dir != MOV_DOWN)
				obj->m_dir = MOV_UP;
		}
		else if (GetAsyncKeyState(0x53) || GetAsyncKeyState(0x28)) {	//s
			if (obj->m_dir != MOV_UP)
				obj->m_dir = MOV_DOWN;
		}
		else if (GetAsyncKeyState(0x41) || GetAsyncKeyState(0x25)) {//a
			if (obj->m_dir != MOV_RIGHT)
				obj->m_dir = MOV_LEFT;
		}
		else if (GetAsyncKeyState(0x44) || GetAsyncKeyState(0x27)) {//d
			if (obj->m_dir != MOV_LEFT)
				obj->m_dir = MOV_RIGHT;
		}
		else {
			KeyDelayed = false;
			return;
		}
	}
	KeyDelayed = true;

}

void XInputClass::ResetDelayFlag()
{
	this->KeyDelayed = false;
}

