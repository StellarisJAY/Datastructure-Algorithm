// 二分查找非递归方法
int BinarySearch(int* array, int num, int n)
{
	int low = 1, high = n;
	int mid = (low + high) / 2;

	while (array[mid] != num && low < high)
	{
		if (array[mid] > num)
			high = mid - 1;
		else if (array[mid] < num)
			low = mid + 1;
		mid = (low + high) / 2;
	}
	return low < high ? mid : -1;
}

// 二分查找递归方法
int BinarySearchRecursion(int* array, int num, int start, int end)
{
	int mid = (start + end) / 2;
	if (num > array[end] || num < array[start])
		return -1;
	if (num == array[mid])
		return mid;
	else if (num < array[mid])
		return BinarySearchRecursion(array, num, start, mid - 1);
	else if (num > array[mid])
		return BinarySearchRecursion(array, num, mid + 1, end);
}