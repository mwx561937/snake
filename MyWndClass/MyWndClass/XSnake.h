#pragma once
#include "XObject.h"
#include "XFood.h"

struct XBlock
{
	long x;
	long y;
	unsigned width;
	unsigned height;

	unsigned int color;
	XBlock* pNext;
	XBlock* pPrev;
	bool operator == ( const XBlock& otherBlk) {
		return this->x == otherBlk.x && this->y == otherBlk.y;
	}

};


class XSnake :
	public XObject
{
public:
	XSnake();
	~XSnake();

	void DrawObject(void*);
	void MoveX();
	void MoveY();
	void Move();

	bool IsEatten(XFood*);
	bool IsCrash();

	int GetLength();
	void AddBlock(int);

	void SetUnreal();
	void ResetUnreal();


private:
	XBlock* m_pHead;
	XBlock* m_pTail;
	XBlock* m_pPreTail;

	unsigned int m_len;
	unsigned int m_blockSize;
	
	bool m_IsUnreal;
	DWORD m_unrealTime;
	DWORD m_lastUnrealTime;

};

