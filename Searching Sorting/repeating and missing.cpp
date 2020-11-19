#include <iostream>
using namespace std;

/*

Let x be the missing and y be the repeating element.
Get the sum of all numbers using formula S = n(n+1)/2 – x + y
Get product of all numbers using formula P = 1*2*3*…*n * y / x
The above two steps give us two equations, we can solve the equations and get the values of x and y.

*/
void misrep(int arr[],int n){

	int sum=0,asum;
	int product=1,aproduct=1;
	int i;
	int x,y;
	asum=(n*(n+1))/2;	

	for(i=0;i<n;i++){
		sum+=arr[i];
		product*=arr[i];
		aproduct*=(i+1);
	}

	// x-y=a
	// x/y=b
	// y=a/(b-1)
	// x=a+y
	int a,b;
	a=asum-sum;
	b=aproduct/product;

	y=a/(b-1);	
	x=a+y;
	
	printf("Missing: %d\nRepeated: %d\n",x,y);
}

int main(){

	int arr[]={4, 3, 6, 2, 1, 1};
	int n = sizeof(arr)/sizeof(arr[0]);  

	misrep(arr,n);

	return 0;
}