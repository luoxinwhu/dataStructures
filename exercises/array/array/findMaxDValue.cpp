/*有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
给定数组A及它的大小n，请返回最大差值。
测试样例：
[10,5],2
返回：0
*/



#include <iostream>
#include <vector>
using namespace std;

int getDis(vector<int> A, int n) 
{
	if (n <= 1)
		return 0;

	int res = 0;
	for (int j = 0; j < n; j++) 
	{
		for (int i = j+1; i<n; i++)  //保证了b>a
		{
			if (A[i]>A[j]) 
			{
				int dis = A[i] - A[j];
				if (dis>res)  res = dis;
			}
		}
	}
	return res;
}

//int main()
//{
//	vector<int> A; 
//	int data[] = { 10,5,3,2,89 };
//	for (int i = 0; i < 5; i++)
//	{
//		A.push_back(data[i]);
//	}
//	cout << getDis(A, A.size()) << endl;
//	return 0;
//}