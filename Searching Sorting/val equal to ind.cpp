#include <iostream>
using namespace std;

int binaryVEI(int arr[],int n){
	int low=0;
	int high=n-1;

	while(low<=high){
		int mid=(low+high)/2;

		if(arr[mid]==mid)
			return mid;
		if(arr[mid]<mid)
				low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

 
int main(){

	int arr[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};  
    int n = sizeof(arr)/sizeof(arr[0]);  

    cout<<binaryVEI(arr,n);





	return 0;
}