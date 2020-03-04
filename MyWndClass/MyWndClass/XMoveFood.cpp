#include "XMoveFood.h"
using namespace std;



void XThread::run() {

}


XMoveFood::XMoveFood()
{
	m_x = 300;
	m_y = 300;
	m_moveDuringTime = 200;
	m_IncreaseBlock = 5;
}


XMoveFood::~XMoveFood()
{
}

void XMoveFood::LoadSnake(XSnake* targ)
{
	m_snake = targ;
}

void XMoveFood::Go()
{
	//cout << "m_snake : " << m_snake->m_x << "," << m_snake->m_y << endl;

	if (abs(m_snake->m_x - m_x) < 5 * 20 && abs(m_snake->m_y - m_y) < 5 * 20) {
		if (GetTickCount() - m_moveTime > m_moveDuringTime) {
			m_moveTime = GetTickCount();
			//m_vx = (rand() % 2) * 20;
			m_vx = 20;
			int dir_index = 0;
			if (GetTickCount() - m_directTime > 250) {
				m_directTime = GetTickCount();
				dir_index = rand() % 4;
				switch (dir_index)
				{
				case 0:
					m_dir = MOV_LEFT;
					break;
				case 1:
					m_dir = MOV_UP;
					break;
				case 2:
					m_dir = MOV_RIGHT;
					break;
				case 3:
					m_dir = MOV_DOWN;
					break;
				}
			}

			if (m_dir == MOV_UP) {
				if (m_y > 0)
					m_y -= m_vx;
				else
				{
					m_dir = MOV_DOWN;
				}
			}
			else if (m_dir == MOV_DOWN) {
				if (m_y < 440)
				{
					m_y += m_vx;
				}
				else {
					m_dir = MOV_UP;
				}
			}
			else if (m_dir == MOV_LEFT) {

				if (m_x > 0)
					m_x -= m_vx;
				else {
					m_dir = MOV_RIGHT;
				}
			}
			else if (m_dir == MOV_RIGHT) {
				if (m_x < 620)
					m_x += m_vx;
				else
					MOV_LEFT;
			}

		}

	}


}

void XMoveFood::LevelUp()
{
	if(m_moveDuringTime > 50)
		m_moveDuringTime -= 50;
}

