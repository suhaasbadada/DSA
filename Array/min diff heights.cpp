#include <bits/stdc++.h>
using namespace std;

int minDiff(int arr[],int n,int k){
	
	sort(arr,arr+n);

	int d=arr[n-1]-arr[0];
	
	int small=arr[0]+k;

	int big=arr[n-1]-k;

	if(small>big){
		swap(small,big);
	}

	int i;
	for(i=1;i<n;i++){

		int sub=arr[i]-k;
		int add=arr[i]+k;

		if(sub>=small||add<=big){
			continue;
		}

		if(big-sub<=add-small){
			small=sub;
		}else{
			big=add;
		}
	}

	return min(d,big-small);
}

int main(){

	
	
	int arr[]={1,5,15,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;

	cout<<minDiff(arr,n,k);


	return 0;
}