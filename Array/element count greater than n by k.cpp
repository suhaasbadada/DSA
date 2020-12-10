#include <iostream>
#include <unordered_map>
using namespace std;

void GTnBk(int arr[],int n,int k){

	int i,x=n/k;

	unordered_map <int,int> m;
	for(i=0;i<n;i++){
		m[arr[i]]++;
	}

	for(i=0;i<n;i++){
		if(m[i]>x){
			cout<<arr[i]<<"\n";
		}
	}
}


int main(){
	
	

 	int arr[] = {1,1,2,2,3,5,4,2,2,3,1,1,1}; 
 	int n=sizeof(arr)/sizeof(arr[0]);
 	int k=4;

 	GTnBk(arr,n,k);	// greater than n by k

	return 0;
}