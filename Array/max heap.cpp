#include <iostream>
using namespace std;

void heapify(int arr[],int n,int i){
	
	int largest=i;	// largest as root
	int l=2*i+1;	// left=2i+1
	int r=2*i+2;	// right=2i+2

	// If left child is larger than root 
	if(l<n && arr[l]>arr[largest]){
		largest=l;
	}

	// If right child is larger than largest so far 
	if(r<n && arr[r]>arr[largest]){
		largest=r;
	}

	// If largest is not root (both child larger than root)
	if(largest!=i){
		swap(arr[i],arr[largest]);

		// Recursively heapify the affected sub-tree 
        heapify(arr,n,largest); 
	}
}


void buildHeap(int arr[],int n){
	int startInd=(n/2)-1;
	int i;
	for(i=startInd;i>=0;i--){
		heapify(arr,n,i);
	}
}


void printHeap(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}



int main(){
	
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 


	buildHeap(arr, n); 

	printHeap(arr, n); 

	return 0;
}