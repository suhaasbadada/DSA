#include <iostream>
#include <algorithm>
using namespace std;

bool tripletSum(int arr[],int n,int sum){
	sort(arr,arr+n);
	
	int i,j,l,r;

	for(i=0;i<n-2;i++){
	 	l=i+1;
	 	r=n-1;

	 	while(l<r){
	 		if(arr[i]+arr[l]+arr[r]==sum){
	 			cout<<arr[i]<<" "<<arr[l]<<" "<<arr[r]<<"\n";
	 			return true;
	 		}else if(arr[i]+arr[l]+arr[r]<sum){
	 			l++;
	 		}else{
	 			r--;
	 		}
	 	}
	}
	 
	return false;
}

int main(){
	int arr[]={1,4,45,6,10,8}; 
    int sum=22; 
    int n=sizeof(arr)/sizeof(arr[0]); 

    tripletSum(arr,n,sum);

	return 0;
}