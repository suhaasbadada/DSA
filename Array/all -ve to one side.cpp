#include <bits/stdc++.h>
using namespace std;

void negativeLeft(int arr[],int n){
	int i,counter=0;

	for(i=0;i<n;i++){
		if(arr[i]<0){
			if (i!=counter){
				swap(arr[i],arr[counter]);				
			}
			counter++;
			
		}
	}
}





int main(){

	int arr[]={-12, 11, -13, -5, 6, -7, 5, -3, -6};
	int n=sizeof(arr)/sizeof(arr[0]);

	negativeLeft(arr,n);
	int i;
	for(i=0;i<n;i++){
	cout<<arr[i]<<" ";
	}


	return 0;
}