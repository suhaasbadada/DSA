#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int CountReversals(string expression){
	// first step remove balanced part
	int len=expression.length();

	if(len%2!=0)
		return -1;

	stack <char> s;
	int i;

	for(i=0;i<len;i++){
		if(expression[i]=='}'&&!s.empty()){
			if(s.top()=='{'){
				s.pop();
			}else{
				s.push(expression[i]);
			}
		}else{
			s.push(expression[i]);
		}
	}

	int reducedLen=s.size();

	int n=0,m=0;
	while(!s.empty()){

		if(s.top()=='{'){
			n++;
		}else{
			m++;
		}

		s.pop();
	}

	return (reducedLen/2+n%2);
}

int main(){
	string expr = "}{{}}{{{"; 

	cout<<CountReversals(expr);

	return 0;
}
