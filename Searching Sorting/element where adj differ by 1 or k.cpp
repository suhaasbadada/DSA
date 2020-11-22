#include <iostream>
using namespace std;

int search1(int arr[],int n,int x){
	int i=0;

	while(i<n){
		
		if(arr[i]==x){
			return i;
		}

		i+=abs(arr[i]-x);
	}
	return -1;
}


int searchk(int arr[],int n,int x,int k){
	int i=0;

	while(i<n){
		if(arr[i]==x){
			return i;
		}

		i+=max(1,abs(arr[i]-x)/k);

	}
	return -1;
}



int main(){

	int arr1[]={8, 7, 6, 7, 6, 5, 4, 3, 2, 3, 4, 3};
	int n1=sizeof(arr1)/sizeof(arr1[0]);
	int x1=3;

	cout<<search1(arr1,n1,x1)<<"\n";

	int arr2[]={20, 40, 50, 70, 70, 60};
	int n2=sizeof(arr2)/sizeof(arr2[0]);
	int x2=60;
	int k=20;	// the at most difference b/w adjacent elements

	cout<<searchk(arr2,n2,x2,k)<<"\n";



	return 0;
}