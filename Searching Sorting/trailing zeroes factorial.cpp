#include <bits/stdc++.h>
using namespace std;

// number of zeroes is equal to number of 5’s in prime factors of x!

/*
int trailingZeroesNum(int z){

}
*/
int TrailingZeroes(int n){
	int numberOfFives=0;
	
	while(n>=5){
		numberOfFives+=(floor(n/5));
		n=floor(n/5);
	}
	return numberOfFives;
}

bool check(int p,int z){
	
	int check_z=TrailingZeroes(p);
	return (z==check_z);
}

int findNum(int n) 
{ 
    // If n equal to 1, return 5. 
    // since 5! = 120. 
    if (n==1) 
        return 5; 
  
    // Initalising low and high for binary 
    // search. 
    int low=0; 
    int high=5*n; 
  
 
    while (low<high)    // Binary Search. 
    { 
        int mid = (low+high)/2; 
  
        // Checking if mid's factorial contains 
        // n trailing zeroes. 
        if (check(mid, n)) 
            high = mid; 
        else
            low = mid+1; 
    } 
  
    return low; 
} 



int main(){

	

	//int n=100;	
	//cout<<TrailingZeroes(n)<<"\n";	// trailing zeroes for 100!

	int z=6;

	cout << findNum(z) << endl; 
	//cout<<();

	return 0;
}