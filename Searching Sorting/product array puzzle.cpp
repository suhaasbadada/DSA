#include <iostream>
using namespace std;

void puzzle(int arr[],int n){
	int i,p=1;
	
	for(i=0;i<n/2;i++){
		p*=arr[i];
		p*=arr[n-i-1];
	}
	if(n%2!=0){
		p=p*arr[n/2];
	}

	for(i=0;i<n;i++){
		cout<<p/arr[i]<<" "<<" ";
	}
}	


int main(){

	 int arr[]={10,3,5,6,2};
	 int n=sizeof(arr)/sizeof(arr[0]);

	 puzzle(arr,n);
	return 0;
}