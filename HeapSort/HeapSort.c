// ������������µĶ�
void Adjust(int* array, int i, int n)
{
	int j = 2 * i;
	int temp = array[i];

	while (j <= n)
	{
		if (j < n && array[j] < array[j + 1])
			j++;
		if (temp >= array[j])
			break;
		array[j / 2] = array[j];
		j = j * 2;
	}
	array[j / 2] = temp;                    // ��������ײ��ǣ�������ڵ�ı���˸�ֵ��Ҫ�ѱ��ı��iλ�õ�ֵ�������������
}

// ���������
// �Ƚ�����ʼ�ѣ�Ȼ��Ѷ��������ֵ�������ֵ�ƶ�����ȷλ�ã���ʱ���ѱ��ƻ���������Ҫ���µ�����������һ���µĶ�
void HeapSort(int* array, int n)
{
	int i, j;

	for (i = n / 2; i >= 1; i--) {        // ������ʼ��
		Adjust(array, i, n);
	}
	for (j = n - 1; j >= 1; j--) {
		int temp = array[j + 1];
		array[j + 1] = array[1];
		array[1] = temp;
		Adjust(array, 1, j);
	}
}