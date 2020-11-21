#include <iostream>
using namespace std;


int Exists(int a,int b,int d){
 if (d == 0){
    return (a==b);
 }
else{
	return ((b-a)%d==0 && (b-a)/d>=0);
	}
}


int main(){

	int a=1;	// a -> initial number 
	int b=2;	// b -> check number  
	int d=3;	// d -> common difference	
				
	cout<<Exists(a,b,d)<<"\n";

	return 0;
}

