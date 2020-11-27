#include <iostream>
using namespace std;

int minOpsForPalindrome(int arr[],int n){
	int i,j;
	i=0;
	j=n-1;
	int count=0;
	while(i<=j){

		if(arr[i]==arr[j]){
			i++;
			j--;
		}
		else if(arr[i]>arr[j]){
			j--;
			arr[j]+=arr[j+1];
			count++;

		}else{
			i++;
			arr[i]+=arr[i-1];
			count++;
		}
	}
	return count;
}



int main(){
	int arr[] = {1, 4, 5, 9,1}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<minOpsForPalindrome(arr,n)<<"\n";

	return 0;
}