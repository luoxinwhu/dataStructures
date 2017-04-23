
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {

	for (int i = 0; i < (int)f.size(); i++)
	{
		int row = f[i][0] - 1; 
		int col = f[i][1] - 1;
					
		//异或运算实现0,1翻转
		if(row-1>=0)	A[row - 1][col] ^= 1;	//上
		if(row+1<4)		A[row + 1][col] ^= 1; //下
		if(col-1>=0)	A[row][col - 1] ^= 1; //左
		if(col+1<4)		A[row][col + 1] ^= 1; //右
	}
	return A;
}

//int main()
//{
//	vector<vector<int>> A, f, res;
//	vector<int> f1,a1;
//	int data;
//	
//	cout << "请输入棋盘矩阵：" << endl;
//	for (int i = 0; i < 4; i++)
//	{
//		A.push_back(a1);
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cin >> data;
//			A[i].push_back(data);
//		}
//		
//	}
//
//	cout << "请输入需要翻转的支点坐标：" << endl;
//	for (int i = 0; i < 3; i++)
//	{
//		f.push_back(f1);
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cin >> data;
//			f[i].push_back(data);
//		}
//		
//	}
//
//
//	res = flipChess(A,f);
//	cout << endl;
//	cout << "翻转后的棋盘矩阵是：" << endl;
//	for (int i = 0; i < (int)A.size(); i++)
//	{
//		for (int j = 0; j < (int)A[0].size(); j++)
//		{
//			cout << res[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}