#include <bits/stdc++.h>
using namespace std;

/*
void PrintMerged(int arr1[],int arr2[],int m,int n){

	int farr[7];

	int indices=min(m,n);

	int j=0;
	int i;

	for(i=0;i<indices;i++){
		if(arr1[i]>arr2[i]){

			farr[j]=arr2[i];
			farr[j+1]=arr1[i];
			
		}
		else if(arr1[i]<arr2[i]){
			farr[j]=arr1[i];
			farr[j+1]=arr2[i];
			
		}
		else{
			farr[j]=arr1[i];
			
		}
		
		j+=2;
	}

	int farrlen=sizeof(farr)/sizeof(farr[0]);

	for(i=0;i<7;i++){
		cout<<farr[i]<<" ";
	}

}

*/

void printIntersection(int arr1[],int arr2[],int m,int n){
	int i=0,j=0;
	
	while(i<m && j<n){
		if(arr1[i]<arr2[j]){
			i++;
		}
		else if (arr2[j]<arr1[i]){
			j++;
		}
		else{
			cout<<arr2[j]<<" ";
			i++;
			j++;
		}
	}		
}

int main(){

	int arr1[]={1, 3, 4, 5, 7};
	int arr2[]={2, 3, 5, 6}; 

	int m=sizeof(arr1)/sizeof(arr1[0]);
	int n=sizeof(arr2)/sizeof(arr2[0]);

	printIntersection(arr1,arr2,m,n);

	return 0;
}