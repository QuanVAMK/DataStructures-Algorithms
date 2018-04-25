#include <iostream>

void SwapElement(int* arr, int i1, int i2)
{
	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

/** Partition algorithm to choose a pivot and re-arrange array so that smaller elements are to the left
	of the pivot and bigger elements are to the right of it (pivot is the last index & equal values can go either way) */
int Partition(int* arr, int low, int high)
{
	int Pivot = high;
	int i = low - 1; // Index of smallest element < arr[Pivot]
	for (int j = low; j <= high - 1; j++)
	{
		// It seems that arr[j] = Pivot doesn't matter at all (it will miraculously fix itself)
		// So it is safe to put arr[j] <=/< arr[Pivot]
		if (arr[j] < arr[Pivot])
		{
			i++;
			SwapElement(arr, i, j);
		}
	}
	SwapElement(arr, i + 1, Pivot);
	return i + 1;
}

/** low = starting index, high = ending index */
void QuickSort(int* arr, int low, int high)
{
	// Are there any chance low > high ?
	if (low < high)
	{
		/** pi = partition index. After the algorithm, arr[pi] should be at the right place */
		int pi = Partition(arr, low, high);

		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
}

int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int arr2[] = { 30, 20, 80, 30, 50, 40 };

	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}