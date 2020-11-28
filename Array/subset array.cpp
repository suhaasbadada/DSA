#include <iostream>
#include <set>
using namespace std;

bool isSubset(int arr1[],int arr2[],int n1,int n2){
	set <int> hashset;
	int i;
	for(i=0;i<n1;i++){
		hashset.insert(arr1[i]);
	}

	for(i=0;i<n2;i++){
		if(hashset.find(arr2[i])==hashset.end())
			return false;
	}
	return true;
}


int main(){

	int arr1[]={11,1,13,21,3,7};
	int arr2[]={11,3,7,1};
	int n1=sizeof(arr1)/sizeof(arr1[0]); 
    int n2=sizeof(arr2)/sizeof(arr2[0]); 

    isSubset(arr1,arr2,n1,n2)?(cout<<"arr2 subset of arr1"):(cout<<"arr2 not a subset of arr1");

	return 0;
}