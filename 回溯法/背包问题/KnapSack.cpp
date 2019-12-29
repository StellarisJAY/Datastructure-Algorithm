#include <iostream>

#define MAXN 10
using namespace std;

int n;                   // ��Ʒ�ܸ���
int w[MAXN + 1] = { 0 }; // ��Ʒ����
int v[MAXN + 1] = { 0 }; // ��Ʒ��ֵ
int weight;              // ��������

int x[MAXN + 1] = { 0 }; // ���Ž⣬x[i]=1�������i����Ʒ��x[i]=0�򲻷���
int maxValue = -1;       // ���Ž�ֵ
int rw = 0;              // ʣ����Ʒ������


/* �ӵ�i����Ʒ��ʼ���뱳���Ļ�����ⷽ��
 * @param tw       ��ǰ������
 * @param tv       ��ǰ�ܼ�ֵ
 * @param rw       ��ǰʣ����Ʒ��������
 * @param solution ������
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
	KnapSack(1, 0, 0, rw, s);     // �ӵ�һ����Ʒ��ʼ���뱳��
	

	cout << "��Ʒ������" << n << endl;
	cout << "����������" << weight << endl;
	for(int k = 1; k <= n; k++)
		cout << "��Ʒ" << k << ": w=" << w[k] << ", v=" << v[k] << endl;

	cout << "\n\n������Ʒ��";
	for (int j = 1; j <= n; j++)
	{
		if (x[j] == 1) {
			cout << j << " ";
		}
	}
	cout << endl;
	cout << "���Ž⣺" << maxValue << endl;
	return 0;
}

void KnapSack(int i, int tw, int tv, int rw, int solution[MAXN + 1])
{
	if (i > n)                   // Ҷ�ӽ�㣬��ʼ�ж��Ƿ���Ͻ�Ҫ��
	{
		if (tw == weight && tv > maxValue)  // �����Ҫ�����������ڱ������������ܼ�ֵ������һ�����ܼ�ֵ
		{
			maxValue = tv;
			for (int j = 1; j <= n; j++) { // �������鸳ֵ��ȫ�ֱ�����
				x[j] = solution[j];
			}
		}
	}
	else
	{
		if (tw + w[i] <= weight)          // ���֦�����뵱ǰ��Ʒ����
		{
			solution[i] = 1;
			KnapSack(i + 1, tw + w[i], tv + v[i], rw - w[i], solution); // �����i����Ʒ
		}
		solution[i] = 0;
		if (rw + tw > weight)             // �Ҽ�֦��ʣ�����������ϵ�ǰ������Ҳ�޷�װ������
		{
			KnapSack(i + 1, tw, tv, rw - w[i], solution);    // �������i����Ʒ
		}

	}
}
/*
�������ݣ�
4 6
5 4
3 4
2 3
1 1
*/