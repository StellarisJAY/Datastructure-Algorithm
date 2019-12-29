#include <iostream>

#define MAXN 10
using namespace std;

int n;                   // 物品总个数
int w[MAXN + 1] = { 0 }; // 物品重量
int v[MAXN + 1] = { 0 }; // 物品价值
int weight;              // 背包容量

int x[MAXN + 1] = { 0 }; // 最优解，x[i]=1即放入第i个物品，x[i]=0则不放入
int maxValue = -1;       // 最优解值
int rw = 0;              // 剩余物品总重量


/* 从第i个物品开始放入背包的回溯求解方法
 * @param tw       当前总重量
 * @param tv       当前总价值
 * @param rw       当前剩下物品的总重量
 * @param solution 解数组
 */
void KnapSack(int i, int tw, int tv, int rw, int solution[MAXN + 1]);

int main(void)
{
	cin >> n;
	cin >> weight;

	
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		cin >> v[i];
		rw += w[i];
	}
	int s[MAXN + 1];
	KnapSack(1, 0, 0, rw, s);     // 从第一个物品开始放入背包
	

	cout << "物品个数：" << n << endl;
	cout << "背包容量：" << weight << endl;
	for(int k = 1; k <= n; k++)
		cout << "物品" << k << ": w=" << w[k] << ", v=" << v[k] << endl;

	cout << "\n\n放入物品：";
	for (int j = 1; j <= n; j++)
	{
		if (x[j] == 1) {
			cout << j << " ";
		}
	}
	cout << endl;
	cout << "最优解：" << maxValue << endl;
	return 0;
}

void KnapSack(int i, int tw, int tv, int rw, int solution[MAXN + 1])
{
	if (i > n)                   // 叶子结点，开始判断是否符合解要求
	{
		if (tw == weight && tv > maxValue)  // 满足解要求：总重量等于背包容量，且总价值大于上一个解总价值
		{
			maxValue = tv;
			for (int j = 1; j <= n; j++) { // 将解数组赋值到全局变量中
				x[j] = solution[j];
			}
		}
	}
	else
	{
		if (tw + w[i] <= weight)          // 左剪枝：放入当前物品超重
		{
			solution[i] = 1;
			KnapSack(i + 1, tw + w[i], tv + v[i], rw - w[i], solution); // 放入第i个物品
		}
		solution[i] = 0;
		if (rw + tw > weight)             // 右剪枝：剩余总重量加上当前总重量也无法装满背包
		{
			KnapSack(i + 1, tw, tv, rw - w[i], solution);    // 不放入第i个物品
		}

	}
}
/*
测试数据：
4 6
5 4
3 4
2 3
1 1
*/