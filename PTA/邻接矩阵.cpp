#include<iostream>
#include<stack>
using namespace std;
int N, M, S, D;
int Grap[505][505][2] = { 0 };	// 起点 终点 距离和价格
int minPath(int s)
{
	int min = 501;
	int minpath = 0;
	for (int i = 0; i < N; i++)
	{
		if (Grap[s][i][0] != 0)
		{
			if (Grap[s][i][0] < min)
			{
				min = Grap[s][i][0];
				minpath = i;
			}
		}
	}
	return minpath;	// 返回非零最小值
}
void merge(int s, int m)
{
	for (int i = 0; i < N; i++)
	{
		if (i == s) continue;
		// 距离不同
		if (Grap[s][m][0] + Grap[m][i][0] < Grap[s][i][0])
		{
			Grap[s][i][0] = Grap[s][m][0] + Grap[m][i][0];
			Grap[s][i][1] = Grap[s][m][1] + Grap[m][i][1];
 		}
		// 距离相同
		else if (Grap[s][m][0] + Grap[m][i][0] == Grap[s][i][0])
		{
			if (Grap[s][m][1] + Grap[m][i][1] < Grap[s][i][1])
			{
				Grap[s][i][0] = Grap[s][m][0] + Grap[m][i][0];
				Grap[s][i][1] = Grap[s][m][1] + Grap[m][i][1];
			}
		}
	}
	Grap[s][m][0] = 0;
}
void bestWay()
{
	int minpath;
	while (1)
	{
		minpath = minPath(S);
		if (minpath != D)
			merge(S, minpath);
		else break;
	}
	cout << Grap[S][D][0] << ' ' << Grap[S][D][1];
}
int main()
{
	cin >> N >> M >> S >> D;
	// 初始化
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				Grap[i][j][0] = 0;
			else 
				Grap[i][j][0] = 505;
		}
	// 赋值
	for (int i = 0; i < M; i++)
	{
		int s, d, distance, price;
		cin >> s >> d >> distance >> price;
		Grap[s][d][0] = distance;
		Grap[d][s][0] = distance;
		Grap[s][d][1] = price;
		Grap[d][s][1] = price;
	}
	bestWay();
	return 0;
}