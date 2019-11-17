int BinarySearch(int* array, int num, int n)
{
	int low = 0, high = n - 1;
	int mid = (low + high) / 2;

	while (array[mid] != num && low < high)
	{
		if (array[mid] > num)
			high = mid - 1;
		else if (array[mid] < num)
			low = mid + 1;
		mid = (low + high) / 2;
	}
	return mid;
}