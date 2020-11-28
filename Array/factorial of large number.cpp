#include <iostream>
using namespace std;

#define MAX 500


int mulitply(int x,int res[],int res_size){
	int i,carry=0;

	for(i=0;i<res_size;i++){
		int product=res[i]*x+carry;

		res[i]=product%10;

		carry=product/10;
	}

	while(carry){
		res[res_size]=carry%10;
		carry/=10;
		res_size++;
	}

	return res_size;
}

void factorial(int n){
	int res[MAX];
	int res_size=1;
	res[0]=1;
	for(int x=2;x<=n;x++){
		res_size=mulitply(x,res,res_size);
	}

	for(int i=res_size-1;i>=0;i--){
		cout<<res[i];
	}
}









int main(){
		
	int i;

	for(i=0;i<=100;i++){
		factorial(i);
		cout<<"\n";
	}

	return 0;
}