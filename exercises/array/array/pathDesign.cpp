/*题目描述
现在有一个城市销售经理，需要从公司出发，去拜访市内的商家，已知他的位置以及商家的位置.
但是由于城市道路交通的原因，他只能在左右中选择一个方向，在上下中选择一个方向，现在问他有多少种方案到达商家地址。
给定一个地图map及它的长宽n和m，其中1代表经理位置，2代表商家位置，-1代表不能经过的地区，0代表可以经过的地区，请返回方案数，保证一定存在合法路径。保证矩阵的长宽都小于等于10。

测试样例：
[[0,1,0],[2,0,0]],2,3
返回：2
*/



#include <iostream>
#include <vector>
using namespace std;

int countPath(vector<vector<int> > map, int n, int m) {
	// n长，m宽
	int people_x, people_y, store_x, store_y;
	int flag = 0;

	for (int i = 0; i<n; i++)
	{
		if (flag == 2) //商家和经理都找到了
			break;

		for (int j = 0; j<m; j++)
		{

			if (map[i][j] == 1)
			{ 	//找到经理
				people_x = i;
				people_y = j;
				flag++;
			}
			if (map[i][j] == 2)
			{	//找到商家
				store_x = i;
				store_y = j;
				flag++;
			}
		}
	}

	//设定方向
	int dir_x = people_x < store_x ? 1 : -1; // 1：向下，-1:向上
	int dir_y = people_y < store_y ? 1 : -1; // 1：向右，-1：向左        


	/*初始化边界*/
	for (int i = people_x + dir_x; i != (store_x + dir_x); i += dir_x) //纵向初始化
	{//若此点可以走，则用上一步的状态更新它
		
		map[i][people_y] = (map[i][people_y] == -1) ? 0 : map[i - dir_x][people_y];
	}

	for (int j = people_y + dir_y; j != (store_y + dir_y); j += dir_y) //横向初始化
	{
		map[people_x][j] = (map[people_x][j] == -1) ? 0 : map[people_x][j - dir_y];
	}

	//动态规划
	for (int i = people_x + dir_x; i != (store_x + dir_x); i += dir_x)
	{
		for (int j = people_y + dir_y; j != (store_y + dir_y); j += dir_y)
		{
			//如果当前点可走，路径数横、纵两个方向的路径方案数总和，循环的过程中实现累加
			map[i][j] = map[i - dir_x][j] + map[i][j - dir_y];
		}
	}//退出循环时，刚好走到商家

	return map[store_x][store_y];
}

int main()
{
	int n, m, data;
	vector<int> elem;	//行矢量
	vector<vector<int>> map;
	cout << "请输入地图矩阵的长:";
	cin >> n;
	cout << "请输入地图矩阵的宽:";
	cin >> m;
	cout << "请输入地图矩阵：" << endl;
	for (int i = 0; i < n; i++)
	{
		map.push_back(elem);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> data;
			map[i].push_back(data);
		}
	}

	cout << "方案总数是：" << countPath(map,n,m) << endl;
	return 0;
}