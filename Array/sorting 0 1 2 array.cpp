#include <bits/stdc++.h>
using namespace std;

/*
    Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
    Traverse the array from start to end and mid is less than high. (Loop counter is i)
    If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
    If the element is 1 then update mid = mid + 1
    If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
    Print the output array.


    basic logic - low should  0s, mid 1s and high 2s
*/

void sort012(int arr[],int n){
	int low=0;
	int mid=0;
	int high=n-1;

	while(mid<=high){
		switch (arr[mid]){
			case 0:
				swap(arr[low++],arr[mid++]);
				break;

			case 1:
				mid++;
				break;
			case 2:
				swap(arr[mid],arr[high--]);
				break;
		}
	}



}






int main(){

	int arr[]={0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int n=sizeof(arr)/sizeof(arr[0]);

	sort012(arr,n);

	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}

