#include <iostream>
using namespace std;

void array_max_min(int arr[],int n){
	int i;
	int max=arr[0];
	for(i=1;i<n;i++){
		if (arr[i]>max){
			max=arr[i];
		}
	}
	int min=arr[0];
	for(i=1;i<n;i++){
		if (arr[i]<min){
			min=arr[i];
	}
	}

	cout<<"Array max:";
	cout<<max;
	cout<<"\n";
	cout<<"Array min:";
	cout<<min;
	cout<<"\n";
}




int main(){


	int arr[]={1,2,3,4};
	int n=4;

	array_max_min(arr,n);

    

    return 0;
}