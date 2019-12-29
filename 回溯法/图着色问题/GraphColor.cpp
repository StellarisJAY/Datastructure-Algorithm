#include <iostream>

#define MAXN 20

int n, k, m; // �����������������ɫ����
int G[MAXN][MAXN] = { 0 };        // ����ͼ���ڽӾ���

int Count = 0;      // ������
int x[MAXN];        // �⣺x[i]��ʾ��i�������ɫ

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
	// ��ʼ���ڽӾ���
	for (int i = 1; i <= k; i++)
	{
		cin >> x;
		cin >> y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	
	GraphColor(1);
	cout << "�������������" << Count << endl;
	return 0;
}

void displaySolution()
{
	cout << "��" << Count << "�����������" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << ",";
	}
	cout << endl;
}

bool Same(int i)
{
	for (int j = 1; j <= n; j++)      // ����ÿһ�����ж���û��ͬɫ�ĵ�
	{
		if (G[j][i] == 1 && x[j] == x[i]) { // ��������������ɫ��ͬ
			return true;
		}
	}
	return false;
}

void GraphColor(int i)
{
	if (i > n) {                     // ����Ҷ�ӽ�㣬����һ�ֽ�
		Count++;
		displaySolution();
	}
	else {
		for (int j = 1; j <= m; j++) {       // ��������ÿһ����ɫ
			x[i] = j;
			if (!Same(i)) // ���û����ɫ��ͬ�����������Ϳ��һ����
				GraphColor(i + 1);
			x[i] = 0; // �õ�δ��ɫ�����ݵ�֮ǰһ����
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