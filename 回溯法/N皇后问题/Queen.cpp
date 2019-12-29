#include <iostream>

#define MAXN 20

using namespace std;

int n; // 皇后数量

int x[MAXN + 1];  // 解
int Count = 0;

bool place(int i); // 第i个皇后是否能放在该列
void displaySolution() {
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == x[i])
				cout << "|Q";
			else
				cout << "|*";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

void Queen(int i); 

int main(void)
{
	cout << "皇后个数：";
	cin >> n;
	Queen(1);
	cout << n << "皇后问题解个数：" << Count << endl;
	return 0;
}

void Queen(int i)
{
	if (i > n) {             // 叶子结点，输出解
		Count++;
		displaySolution();
	}
	else
	{
		for (int j = 1; j <= n; j++) // 遍历n列判断是否能够放到该列
		{
			x[i] = j;
			if (place(i))           // 该列可以放入则递归到第i+1个皇后
				Queen(i + 1);
			x[i] = 0;               // 回溯到第i-1个
		}
	}
}

bool place(int i)
{
	for (int j = 1; j <= i - 1; j++)                 // 判断第i个皇后是否能够放入该列
	{
		if (x[j] == x[i] || abs(x[i] - x[j]) == abs(i - j)) // 该列已被占用，或者斜线被占用（斜率相同）
			return false;
	}
	return true;
}