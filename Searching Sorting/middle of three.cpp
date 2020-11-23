#include <iostream>
using namespace std;

int middleof3(int a,int b,int c){
	int x=a-b;
	int y=b-c;
	int z=a-c;

	if(x*y>0)
		return b;
	if(x*z>0)
		return c;
	else
		return a;
}


int main(){

	int a=20;
	int b=30;
	int c=40;

	return 0;
}