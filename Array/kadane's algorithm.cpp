#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
	
	int highestMax=0;
	int i,currMax=0;

	for(i=0;i<n;i++){
		currMax=max(arr[i],currMax+arr[i]);
		highestMax=max(highestMax,currMax);
		cout<<currMax<<" "<<highestMax<<"\n";
	}

	return highestMax;
}


int main(){

	int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<kadane(arr,n)<<"\n";

	return 0;
}
