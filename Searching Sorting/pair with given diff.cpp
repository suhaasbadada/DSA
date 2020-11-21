#include <bits/stdc++.h> 
using namespace std; 

bool findPair(int arr[], int n, int d) 
{ 
	int i = 0; 
	int j = 1; 
 
	while (i < n && j < n) 
	{ 
		if (i != j && arr[j] - arr[i] == d) 
		{ 
			cout << "[" << arr[j] << "," << arr[i] << "]"<<"\n"; 
			//return true; 
			i++;
			j++;
		} 
		else if (arr[j]-arr[i] < d) 
			j++; 
		else
			i++; 
	} 

	cout << "No such pair"; 
	return false; 
} 

int main() 
{ 
	int arr[] = {1, 8, 30, 40,90,100}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int d = 60; 
	findPair(arr, n, d); 
	return 0; 
} 

