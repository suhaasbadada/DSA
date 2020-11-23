#include <iostream>
using namespace std;

void PrefixSum(int arr[],int n,int ps_arr[]){
	ps_arr[0]=arr[0];
	int i;
	for(i=1;i<n;i++){
		ps_arr[i]=ps_arr[i-1]+arr[i];
	}
}


int main(){

	int arr[]={10,4,16,20}; 
    int n=sizeof(arr)/sizeof(arr[0]); 
    int ps_arr[n]; 
    int i;
  
    PrefixSum(arr,n,ps_arr); 

    for (i=0;i<n;i++) 
        cout <<ps_arr[i]<< " "; 

	return 0;
}