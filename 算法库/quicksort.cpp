int qsort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);

void quickSort(int arr[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = qsort(arr, low, high);
		quickSort(arr, low, mid - 1);
		quickSort(arr, mid + 1, high);
	}
}

int qsort(int arr[], int left, int right)
{
	int base = arr[left];//基
	int postion = left;//空元素的位置
	while (left < right)
	{
		while ((left < right) && (arr[right] >= base) )
		{
			right--;
		}
		if (arr[right] < base)
		{
			arr[postion] = arr[right];
			postion = right;
			right--;
		}
		while ((left < right) && (arr[left] <= base) )
		{
			left++;
		}
		if (arr[left] > base)
		{
			arr[postion] = arr[left];
			postion = left;
			left++;
		}
	}
	arr[postion] = base;//最终位置存入基
	return postion;//返回基最终的位置
}