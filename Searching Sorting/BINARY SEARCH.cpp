#include <iostream>
using namespace std;

int binarySearchIterative(int arr[],int x,int n){
	int low=0;
	int high=n-1;

	while(low<=high){
		int mid=(low+high)/2;

		if(arr[mid]==x)
			return mid;

		if(arr[mid]<x)
			low=mid+1;
		else
			high=mid-1;

	}

	return -1;
}


int main(){

		int arr[]={11,12,23,24,30,21};
		int n=sizeof(arr)/sizeof(arr[0]);

		cout<<binarySearchIterative(arr,24,n);


	return 0;
}