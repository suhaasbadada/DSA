#include <iostream>
#include <unordered_map>
using namespace std;

int pairsCount(int arr[],int n,int sum){
	unordered_map <int,int> map;
	int i,j;

	for(i=0;i<n;i++){
		map[arr[i]]++;
	}

	int doublecount=0;

	for(i=0;i<n;i++){
		doublecount+=map[sum-arr[i]];

		if(sum-arr[i]==arr[i]){
			doublecount--;
		}
	}

	return doublecount/2;
}

void printPairs(int arr[],int n,int sum){
	unordered_map <int,int> map;
	int i;

	for(i=0;i<n;i++){
		map[arr[i]]++;
	}

	for(i=0;i<n;i++){
		if(sum-arr[i]!=arr[i]){
			cout<<arr[i]<<" "<<sum-arr[i]<<"\n";
		}
	}
}

int main() 
{ 
    int arr[]={1,5,7,-1,5} ; 
    int n=sizeof(arr)/sizeof(arr[0]); 
    int sum=6; 
    
    cout<<pairsCount(arr,n,sum)<<"\n";

    printPairs(arr,n,sum); 
    
    return 0; 
} 