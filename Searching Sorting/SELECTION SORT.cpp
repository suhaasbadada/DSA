#include <iostream>
using namespace std;

void selectionSort(int arr[],int n){
	int i,j,minInd;
	for(i=0;i<n;i++){
		minInd=i;
		for(j=i+1;j<n;j++){
			if(arr[minInd]>arr[j]){
				minInd=j;
			}
			swap(arr[minInd],arr[i]);
		}
	}
}


int main(){

	int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  

    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl;  

	return 0;
}