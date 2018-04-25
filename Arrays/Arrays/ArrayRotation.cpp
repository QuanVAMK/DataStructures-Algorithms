/** Rotates array arr[] of size N by D elements
  	arr[] = 1 2 3 4 5, D = 2 -> 3 4 5 1 2 */

#include <iostream>

/** Rotate array using a temp array Auxiliary space O(D) (normally start at O(1)) */
void RotateArray(int* arr, int* OutArr, int N, int D)
{
	for (int i = 0; i < N; i++)
	{
		if (i+D < N)
			OutArr[i] = arr[i + D];
		else
			OutArr[i] = arr[(i + D) - N];
	}
}

/** Euclidean algorithm, where r(k-2) = r(k-1)*q(k) + r(k) with k = current step of algorithm. 
	So a = r(-2) & b = r(-1) -> (k = 0): a = b*q(0) + r(0) -> (k = 1): b = r(0)*q(1) + r(1) -> ...
	When r(k) = 0 -> r(k-1) is our GCD. Update Complexity 7/4/2018*/
int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }

/** Juggling Algorithm: O(N)??
	Why GCD is the total No of sets? Inner loop increments in steps of D
	& Only terminate when k == i ->  total span (distance) of the loop is some multiple of N. -> LCM(N, D) is that multiple.
	 -> The total No of shifts in 1 cycle = LCM(N, D) / D -> The total No of cycles = N / (LCM(N, D) / D) = GCD(N, D) */
// TODO: Complexity time of the algorithm 30/3/2018
void LeftRotateByGCD(int *arr, int N, int D)
{
	for (int i = 0; i < GCD(N, D); i++)
	{
		int temp = arr[i];
		int j = i;
		while (1)
		{
			int k = j + D;
			if (k >= N)
			{
				k = k - N;
			}
			if (k == i)
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}

}

/** Reversal Algorithm to rotate an arr by D elements by reversing 3 times. O(N) */
void ReverseArr(int *arr, int Start, int End)
{
	int temp = 0;
	while (Start < End)
	{
		temp = arr[End];
		arr[End] = arr[Start];
		arr[Start] = temp;
		Start++;
		End--;
	}
}

void RotateByReversal(int *arr, int N, int D)
{
	ReverseArr(arr, 0, D - 1);
	ReverseArr(arr, D, N - 1);
	ReverseArr(arr, 0, N - 1);
}

/** Utility function to swap part of arr for block-swap algorithm. */
void SwapArr(int *arr, int i1, int i2, int D)
{
	int temp = 0;
	for (int i = 0; i < D; i++)
	{
		temp = arr[i2 + i];
		arr[i2 + i] = arr[i1 + i];
		arr[i1 + i] = temp;
	}
}

// Understand a bit about Block-Swap algorithm: improve recursion 1/4/2018 & increase Comment-Friendly if possible + Complexity Time
void RotateByBlockSwap(int *arr, int N, int D)
{
	/** Initialize A[0..D-1] & B[D..N-1] */
	int SizeA = D;
	int SizeB = N - D;
	while (SizeA != SizeB)
	{
		// 1 Pattern is that: A would increase (0-based): D - D, D - (D-1).. D-1 (The final element it holds) at most. (A > B)
		// B would decrease (0-based): D + (N-D) - D, D + (N-2D) - D.. D (The final element it holds) at least. (B > A)
		// So, usually: B > A until at 1 point A > B -> B would be at D pos & A increment until it's at (D-1) pos
		if (SizeA < SizeB)
		{
			SwapArr(arr, D - SizeA, D + SizeB - SizeA, SizeA);
			SizeB -= SizeA;
		}
		else
		{
			SwapArr(arr, D - SizeA, D, SizeB);
			SizeA -= SizeB;
		}
	}
	/** SizeA is equal to SizeB so we do 1 final swap (The 4th argument of the utility func can either be SizeA/SizeB doesn't matter) */
	SwapArr(arr, D - SizeA, D, SizeA);

}

/** Rotate an arr by rotating one element at each cycle. O(N*D). */
void LeftRotateByOne(int *arr, int N)
{
	int temp = arr[0];
	for (int i = 0; i < N-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[N - 1] = temp;
}

/** Left rotate arr[] D times */
void LeftRotate(int* arr, int N, int D)
{
	for (int i = 0; i < D; i++)
	{
		LeftRotateByOne(arr, N);
	}
}
/*
void PrintArray(int* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}
}
/*
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7};
	int N = sizeof(arr) / sizeof(arr[0]);
	int D = 2;
	PrintArray(arr, N);
	// can't use variable-length array (VLA): int NewArr[n] = { 0 }; in C++ (GCC is okay). The specified length must be a constant-expression
	/* Rotate array using a temp array
	int* NewArr = new int(N);
	if (!NewArr)
	{
		std::cout << "Memory allocation failed!";
		return 1;
	}
	RotateArray(arr, NewArr, N, D);
	delete[]NewArr;

	RotateByBlockSwap(arr, N, D);
	PrintArray(arr, N);
	return 0;
} */