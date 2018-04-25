/** Given an unsorted array of integers, print all triplets with sum less than or equal to a given number. */
#include <iostream>
#include <algorithm>

void PrintAllTriplets(int* A, int n, int sum) {
	// Sort array ascending
	std::sort(A, A + n);

	// Check if triplet is formed by A[i] & pair from sub-array A[i+1,n)
	for (int i = 0; i <= n-3; i++) 
	{
		// Maintain 2 indexes pointing to end-points of sub-array A[i+1,n)
		int low = i + 1;
		int high = n - 1;

		while (low < high) 
		{
			// decrement element with highest value
			if (A[i] + A[low] + A[high] > sum)
				high--;
			else 
			{
				// Print all triplets if <= sum
				for (int j = low + 1; j <= high; j++)
					std::cout << "( " << A[i] << ", " << A[low] << ", " << A[j] << " )" << std::endl;
				low++;
			}
		}
	}
}
/* int main() 
{
	int A[] = { 2, 3 ,4, 5, 7, 9, 1 };
	int sum = 10;

	PrintAllTriplets(A, sizeof(A) / sizeof(A[0]), sum);
	return 0;
}
*/