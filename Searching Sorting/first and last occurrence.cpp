#include <bits/stdc++.h>
using namespace std;

int first(int arr[], int x, int n)
{
	int low = 0, high = n - 1;
	int result = -1;

	while (low <= high)
	{
		int mid = (low + high)/2;
		if (x == arr[mid])
		{
			result = mid;
			high = mid - 1;
		}
		else if (x < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return result;
}

int last(int arr[], int x, int n)
{
	int low = 0, high = n - 1;
	int result = -1;

	while (low <= high)
	{
		int mid = (low + high)/2;
		if (x == arr[mid])
		{
			result = mid;
			low = mid + 1;
		}
		else if (x < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return result;
}

int main()
{
	int arr[]={11,12,13,13,15,15,15};
	int n = sizeof(arr) / sizeof(int);

	int x = 15;
	printf("First Occurrence = %d\t",
		first(arr, x, n));
	printf("\nLast Occurrence = %d\n",
		last(arr, x, n));

	return 0;
}
