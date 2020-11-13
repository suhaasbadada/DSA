#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void cyclicRotate(int arr[],int n){
	int i;
	
	int x=arr[n-1];
	for(i=n-1;i>0;i--){

		arr[i]=arr[i-1];

	}
	arr[0]=x;
}

void acyclicRotate(int arr[],int n){
	int i;

	int x=arr[0];
	for(i=0;i<n-1;i++){
		arr[i]=arr[i+1];
	}

	arr[n-1]=x;
}


int main(){
	
	int arr[]={1,2,3,4};
	int arrcpy[]={1,2,3,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	


	cyclicRotate(arr,n);

	printArr(arr,n);

	acyclicRotate(arrcpy,n);

	printArr(arrcpy,n);


	return 0;
}