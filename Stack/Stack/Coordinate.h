#pragma once

/*Coordinate������
* created by luoxin on 2017/04/12
*/

#include <ostream>
using namespace std;

class Coordinate
{
	friend ostream& operator<< (ostream& out, Coordinate& coor);
public:
	Coordinate(int x=0, int y=0); //Ĭ�Ϲ��캯��
	void printCoordinate();

private:
	int m_iX;
	int m_iY;
};

