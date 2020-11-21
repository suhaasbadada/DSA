#include <iostream>
using namespace std;

int kthOfSorted(int arr1[],int arr2[],int m,int n,int k){
	
	int sorted[m+n];

    int i=0,j=0,d=0;

    while (i<m && j<n)
    {
        if (arr1[i]<arr2[j])
            sorted[d++]=arr1[i++];
        else
            sorted[d++]=arr2[j++];
    }

    while (i<m)
        sorted[d++]=arr1[i++];
    while (j<n)
        sorted[d++]=arr2[j++];
    
    return sorted[k];
}


int kthOptimised(int arr1[],int arr2[],int m,int n,int k){
	int i=0,j=0;
	int counter=-1;

	while(i<m && j<n){
		if(arr1[i]<arr2[j]){
			counter++;
			
			if(counter==k){
				return arr1[i];
			}
			
			i++;
		}

		else{
			
			counter++;

			if(counter==k){
				return arr2[j];
			}
			
			j++;

		}

	}

	 while(i < m) 
    {
        k++;
        if(counter==k)
            return arr1[i];
        i++;
    }
 
    while(j<n) 
    {
        k++;
        if(counter==k)
            return arr2[j];
        j++;
    }

    return -1;

}


int main(){

	int arr1[]={1, 3, 4, 5, 7};
	int arr2[]={2, 3, 5, 6}; 
	//int arr1[]={2,3,6,7,9};
	//int arr2[]={1,4,6,8,10};
	int m=sizeof(arr1)/sizeof(arr1[0]);
	int n=sizeof(arr2)/sizeof(arr2[0]);
	int k=5;

	// 1 2 3 4 6 7 8 9 10
	
	// 1 2 3 3 4 5 5 6 7
	
	printf("My approach 1 O(m+n): %d\n",kthOfSorted(arr1,arr2,m,n,k));

	printf("My approach 2 O(k): %d",kthOptimised(arr1,arr2,m,n,k));	

	return 0;
}