#include <iostream>
using namespace std;

int findPivot(int arr[],int n){
	int pivot;
	int i;
	for(i=0;i<n-1;i++){
		if (arr[i]>arr[i+1]){
				pivot=i;
				break;
		}
	}
	return pivot;
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = (l+r)/2; 
        
        if (arr[m] == x) 
            return m; 
        if (arr[m] < x) 
            l=m+1; 
        else
            r=m-1; 
    } 
    
    return -1; 
} 

int search(int arr[],int n,int key){
	int pivot=findPivot(arr,n);

	 if (pivot == -1) 
        return binarySearch(arr, 0, n - 1, key); 
  
    // If we found a pivot, then first compare with pivot 
    // and then search in two subarrays around pivot 
    if (arr[pivot] == key) 
        return pivot; 
  
    if (arr[0] <= key) 
        return binarySearch(arr, 0, pivot - 1, key); 
  
    return binarySearch(arr, pivot + 1, n - 1, key); 

}



int main(){


	int arr[]={4,5,6,7,0,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=1;
	
	cout<<search(arr,n,x);
	
	return 0;
}



/*

	if(arr[n-1]<arr[0]){
		cout<<binarySearch(arr,0,pivot,x);
	}
	else{
		cout<<binarySearch(arr,pivot,n,x);
	}
*/