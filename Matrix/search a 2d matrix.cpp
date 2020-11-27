#include <iostream>
using namespace std;

void search(int mat[3][4],int n,int searchFor){
	int i,j;
	int smallest=mat[0][0];
	int largest=mat[n-1][n-1];

	if( n==0 || searchFor>largest || searchFor<smallest )
			cout<<"Invalid Matrix";
	i=0;
	j=n-1;

	while(i<n && j>=0){
		
		if(mat[i][j]==searchFor){
			cout<<"Found at:"<<'['<<i<<','<<j<<']'<<"\n";
		}

		if(mat[i][j]>searchFor){
			j--;
		}
		else{
			i++;
		}
	}

}

void binary2dSearch(int mat[][4],int n,int x){
	// treat as 1D matrix and perform binary search 
	int low=0;
	int m=4;
	int high=m*m-1;

	while(low<=high){
		int mid=(low+high)/2;

		if(mat[mid/m][mid%m]==x)		//mat[mid/cols][mid%rows]
			cout<<"Found at:"<<'['<<mid/m<<','<<mid%m<<']'<<"\n";

		if(mat[mid/m][mid%m]<x)
			low=mid+1;
		else
			high=mid-1;
	}
}



int main(){
	
	//sorted matrix

	int mat[][4]={{1,3,5,7},{10,11,16,20},{23,30,34,50},{52,63,72,75}};
	int n=4;
	int searchFor=3;
	int i,j;


	//search(mat,n,searchFor);

	binary2dSearch(mat,4,72);

	return 0;
}