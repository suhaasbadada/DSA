#include <iostream>
using namespace std;

/*
1: If array[0] less than or equal to array[length of array - 1], it means the array is not rotated, so return 0.
2: Initialize start = 0, end = length of array – 1.
3: Repeat following steps till start less than or equal to end 
   (a) Set mid = (start+end)/2.
   (b) If arr[mid]>arr[mid+1] mid is pivot, then break.
   (c) If array[start] less than or equal to array[mid], it means from start to mid, all elements are in sorted order. 
   	   Set start = mid+1, so that we look for pivot in second half of the array.
   (d) Else set end = mid-1, to look for pivot in first half.

*/

int findPivot(int arr[],int n){
	int piv;
	
	if(arr[0]<=arr[n-1]){
		piv=0;
		return piv;
	}

	int start=0;
	int end=n-1;

	while(start<=end){
		int mid=(start+end)/2;

		if(arr[mid]>arr[mid+1]){
			piv=mid;
			return piv;
		}
		else if(arr[start]<=arr[mid]){
			start=mid+1;	//pivot in second half
		}
		else{

			end=mid-1;	//pivot in first half
		}
	}
	return -1;
}




int main(){

	int arr[]={5,5,5,0,1,2,5};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<findPivot(arr,n);
	return 0;
}