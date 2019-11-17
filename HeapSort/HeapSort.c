// 调成数组组成新的堆
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
	array[j / 2] = temp;                    // 遍历到最底层是，如果根节点改变成了该值，要把被改变的i位置的值赋给最后这个结点
}

// 堆排序过程
// 先建立初始堆，然后堆顶就是最大值，将最大值移动到正确位置，此时堆已被破坏，所以需要重新调整序列生成一个新的堆
void HeapSort(int* array, int n)
{
	int i, j;

	for (i = n / 2; i >= 1; i--) {        // 建立初始堆
		Adjust(array, i, n);
	}
	for (j = n - 1; j >= 1; j--) {
		int temp = array[j + 1];
		array[j + 1] = array[1];
		array[1] = temp;
		Adjust(array, 1, j);
	}
}