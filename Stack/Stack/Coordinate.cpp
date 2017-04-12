#include "Coordinate.h"
#include <iostream>
using namespace std;

ostream& operator<< (ostream& out, Coordinate& coor)
{
	out << "("<< coor.m_iX << ","<<coor.m_iY << ")"<<endl;
	return out;
}

Coordinate::Coordinate(int x, int y)
{
	this->m_iX = x;
	this->m_iY = y;
}

void Coordinate::printCoordinate()
{
	cout << "(" << m_iX << "," << m_iX << ")" << endl;
}
