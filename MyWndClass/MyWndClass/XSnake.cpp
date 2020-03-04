#include "XSnake.h"



XSnake::XSnake()
{
	m_len = 3;
	int lastX = 0;
	int lastY = 0;

	m_IsUnreal = false;
	m_blockSize = 20;
	m_vx = m_blockSize;
	m_vy = m_blockSize;
	m_dir = MOV_DOWN;

	m_unrealTime = 5000;

	for (unsigned i=0;i<m_len;++i)
	{
		XBlock* m_pTemp = new XBlock;
		m_pTemp->color = RGB(255, 0, 255);
		m_pTemp->width = m_blockSize;
		m_pTemp->height = m_blockSize;
		m_pTemp->x = lastX + m_pTemp->width;
		m_pTemp->y = m_pTemp->height;

		lastX = m_pTemp->x;
		lastY = m_pTemp->y;
		m_pTemp->pNext = nullptr;
		m_pTemp->pPrev = nullptr;

		if (m_pTail == nullptr) {
			m_pHead = m_pTemp;
			m_pTail = m_pTemp;
		}
		else {
			m_pTail->pNext = m_pTemp;
			m_pTemp->pPrev = m_pTail;
			m_pTemp->pNext = nullptr;
			m_pTail = m_pTemp;
		}




	}

}



XSnake::~XSnake()
{
	XBlock* pTemp = m_pHead;
	while (pTemp != nullptr)
	{
		XBlock* pDel = pTemp;
		pTemp = pTemp->pNext;
		delete pDel;
	}

}

void XSnake::DrawObject(void* hdc)
{
	HDC h = (HDC)hdc;

	//m_pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HBRUSH brush = nullptr;
	if (m_IsUnreal) {
		brush = CreateSolidBrush(RGB(30, 30, 30));
	}
	else
	{
		brush = CreateSolidBrush(RGB(255, 255, 0));
	}
	HBRUSH oldbrush = (HBRUSH)SelectObject(h, brush);



	XBlock* pTemp = m_pHead;
	while (pTemp != NULL)
	{
		if (pTemp == m_pHead)
		{
			Ellipse(h, pTemp->x, pTemp->y, pTemp->x + pTemp->width, pTemp->y + pTemp->height);
		}
		else
		{
			Rectangle(h, pTemp->x, pTemp->y, pTemp->x + pTemp->width, pTemp->y + pTemp->height);
		}
		//RECT rect;
		//rect.left = pTemp->x;
		//rect.top = pTemp->y;
		//rect.right = pTemp->x + pTemp->width;
		//rect.bottom = pTemp->y + pTemp->height;

		//FillRect(h, &rect, brush);
		pTemp = pTemp->pNext;
	}
	SelectObject(h, oldbrush);
	DeleteObject(brush);
}

void XSnake::MoveX()
{
	m_pTail->pNext = m_pHead;
	m_pHead->pPrev = m_pTail;
	m_pHead = m_pTail;

	m_pTail = m_pTail->pPrev;
	m_pTail->pNext = nullptr;
	m_pHead->pPrev = nullptr;
	m_pHead->x = m_pHead->pNext->x + m_vx;

	if (m_pHead->x > 620) {
		m_pHead->x = 0;
	}
	else if (m_pHead->x < 0) {
		m_pHead->x = 620;
	}

	m_pHead->y = m_pHead->pNext->y;



}

void XSnake::MoveY()
{
	m_pTail->pNext = m_pHead;
	m_pHead->pPrev = m_pTail;
	m_pHead = m_pTail;

	m_pTail = m_pTail->pPrev;
	m_pTail->pNext = nullptr;
	m_pHead->pPrev = nullptr;


	m_pHead->x = m_pHead->pNext->x;
	m_pHead->y = m_pHead->pNext->y + m_vy;

	if (m_pHead->y > 440) {
		m_pHead->y = 0;
	}
	else if (m_pHead->y < 0) {
		m_pHead->y = 440;
	}
}

void XSnake::Move()
{
	switch (m_dir)
	{
	case MOV_LEFT:
		if(m_vx > 0)
			m_vx *= -1;
		MoveX();
		break;
	case MOV_RIGHT:
		if(m_vx < 0)
			m_vx *= -1;
		MoveX();
		break;
	case MOV_UP:
		if(m_vy > 0)
			m_vy *= -1;
		MoveY();
		break;
	case MOV_DOWN:
		if(m_vy < 0)
			m_vy *= -1;
		MoveY();
		break;
	}

	m_x = m_pHead->x;
	m_y = m_pHead->y;
}

bool XSnake::IsEatten(XFood* otherObj)
{
	if (abs(m_x - otherObj->m_x) < 20 && abs(m_y - otherObj->m_y) < 20)
	{

		AddBlock(otherObj->GetIncreateBlock());

		//XBlock* newBlock = new XBlock;
		//newBlock->color = RGB(255, 255, 0);
		//newBlock->height = m_blockSize;
		//newBlock->width = m_blockSize;

		//XBlock* pLastPrev = m_pTail->pPrev;
		//XBlock* pLast = m_pTail;
		//if (pLastPrev->x == pLast->x) {
		//	newBlock->x = pLast->x;
		//	int gap = pLastPrev->y - pLast->y;
		//	newBlock->y = pLast->y - gap;
		//}
		//else if (pLastPrev->y == pLast->y) {
		//	newBlock->y = pLast->y;
		//	int gap = pLastPrev->x - pLast->x;
		//	newBlock->x = pLast->x - gap;
		//}

		//m_pTail->pNext = newBlock;
		//newBlock->pPrev = m_pTail;
		//newBlock->pNext = nullptr;
		//m_pTail = newBlock;

		//m_len++;


		return true;
	}
	return false;
}

bool XSnake::IsCrash()
{
	if (m_IsUnreal) {
		return false;
	}
	XBlock* pTemp = m_pHead->pNext;
	while (pTemp != nullptr)
	{
		if (*m_pHead == *pTemp) {
			return true;
		}
		pTemp = pTemp->pNext;
	}
	return false;
}

int XSnake::GetLength()
{
	return m_len;
}

void XSnake::AddBlock(int blocks)
{
	XBlock* newBlock = nullptr;
	for (int i = 0; i < blocks; ++i)
	{
		newBlock = new XBlock;
		newBlock->color = RGB(255, 255, 0);
		newBlock->height = m_blockSize;
		newBlock->width = m_blockSize;


		XBlock* pLastPrev = m_pTail->pPrev;
		XBlock* pLast = m_pTail;
		if (pLastPrev->x == pLast->x) {
			newBlock->x = pLast->x;
			int gap = pLastPrev->y - pLast->y;
			newBlock->y = pLast->y - gap;
		}
		else if (pLastPrev->y == pLast->y) {
			newBlock->y = pLast->y;
			int gap = pLastPrev->x - pLast->x;
			newBlock->x = pLast->x - gap;
		}

		m_pTail->pNext = newBlock;
		newBlock->pPrev = m_pTail;
		newBlock->pNext = nullptr;
		m_pTail = newBlock;




		m_len++;
	}
}

void XSnake::SetUnreal()
{
	m_lastUnrealTime = GetTickCount();
	m_IsUnreal = true;
}

void XSnake::ResetUnreal()
{
	if(GetTickCount() - m_lastUnrealTime > m_unrealTime)
		m_IsUnreal = false;
}

