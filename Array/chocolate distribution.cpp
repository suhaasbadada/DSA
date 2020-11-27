#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int minDiff(int arr[],int n,int students){
	sort(arr,arr+n);
	int i;
	int min_diff = INT_MAX;

	for(i=0;i<n-students+1;i++){
		int diff=arr[i+students-1]-arr[i];
		if(diff<min_diff){
			min_diff=diff;
		}
	}

	return min_diff;
}


int main(){
	int arr[] = {12,4,7,9,2,23,25,41,30,40,28,42,30,44,48,43,50};
    int students=7;  
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<minDiff(arr,n,students)<<"\n";



	return 0;
}