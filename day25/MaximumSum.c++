#include <iostream>
using namespace std;

// subarrays
int maxsum_SIS(int arr[], int n)
{
	int max_sum = arr[0];

	int current_sum = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] < arr[i])
		{
			current_sum = current_sum + arr[i];
			max_sum = max(max_sum, current_sum);
		}

		else // strictly increasing subarray break
		{
			max_sum = max(max_sum, current_sum);
			current_sum = arr[i];
		}
	}

	return max(max_sum, current_sum);
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum sum : " << maxsum_SIS(arr, n);
	return 0;
}
