#include <iostream>

#define MAXN 20

int n, k, m; // 点个数、边数量、颜色数量
int G[MAXN][MAXN] = { 0 };        // 无向图的邻接矩阵

int Count = 0;      // 解数量
int x[MAXN];        // 解：x[i]表示第i个点的颜色

using namespace std;

void displaySolution();
bool Same(int i);
void GraphColor(int i);

int main(void)
{
	int x, y;
	cin >> n;
	cin >> k;
	cin >> m;
	// 初始化邻接矩阵
	for (int i = 1; i <= k; i++)
	{
		cin >> x;
		cin >> y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	
	GraphColor(1);
	cout << "解决方案个数：" << Count << endl;
	return 0;
}

void displaySolution()
{
	cout << "第" << Count << "个解决方法：" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << ",";
	}
	cout << endl;
}

bool Same(int i)
{
	for (int j = 1; j <= n; j++)      // 遍历每一个点判断有没有同色的点
	{
		if (G[j][i] == 1 && x[j] == x[i]) { // 两个点相连且颜色相同
			return true;
		}
	}
	return false;
}

void GraphColor(int i)
{
	if (i > n) {                     // 到达叶子结点，则是一种解
		Count++;
		displaySolution();
	}
	else {
		for (int j = 1; j <= m; j++) {       // 遍历尝试每一种颜色
			x[i] = j;
			if (!Same(i)) // 如果没有颜色相同的情况，则填涂下一个点
				GraphColor(i + 1);
			x[i] = 0; // 该点未填色，回溯到之前一个点
		}
	}
}
/*
4 4 3
1 2
1 3
1 4
2 4
*/