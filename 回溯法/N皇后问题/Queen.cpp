#include <iostream>

#define MAXN 20

using namespace std;

int n; // �ʺ�����

int x[MAXN + 1];  // ��
int Count = 0;

bool place(int i); // ��i���ʺ��Ƿ��ܷ��ڸ���
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
	cout << "�ʺ������";
	cin >> n;
	Queen(1);
	cout << n << "�ʺ�����������" << Count << endl;
	return 0;
}

void Queen(int i)
{
	if (i > n) {             // Ҷ�ӽ�㣬�����
		Count++;
		displaySolution();
	}
	else
	{
		for (int j = 1; j <= n; j++) // ����n���ж��Ƿ��ܹ��ŵ�����
		{
			x[i] = j;
			if (place(i))           // ���п��Է�����ݹ鵽��i+1���ʺ�
				Queen(i + 1);
			x[i] = 0;               // ���ݵ���i-1��
		}
	}
}

bool place(int i)
{
	for (int j = 1; j <= i - 1; j++)                 // �жϵ�i���ʺ��Ƿ��ܹ��������
	{
		if (x[j] == x[i] || abs(x[i] - x[j]) == abs(i - j)) // �����ѱ�ռ�ã�����б�߱�ռ�ã�б����ͬ��
			return false;
	}
	return true;
}