#include <iostream>
using namespace std;

void printArr(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n\n";
}

void ThreeWayPartioning(int arr[],int n,int low,int high){
	int start=0;
	int end=n-1;
	int i=0;

	while (i<=end){

		if(arr[i]<low){
			swap(arr[i++],arr[start++]);

		}
		else if(arr[i]>high){
			swap(arr[i],arr[end--]);

		}else{
			i++;

		}
	}

}


int main(){

	int arr[]={1,14,5,20,4,2,54,20,87,98,3,1,32};
	int n=sizeof(arr)/sizeof(arr[0]);
	int low=14;
	int high=20;

	printArr(arr,n);
	ThreeWayPartioning(arr,n,low,high);
	printArr(arr,n);

	// OUTPUT FORMAT: <low		low-high		>high


	return 0;
}