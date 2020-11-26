#include <iostream>
#include <stack>
using namespace std;

bool  BalancedParanthesesChecker(string exp) 
{ 
	stack<char> s; 
	char x; 

	
	for (int i = 0; i < exp.length(); i++) 
	{ 
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') 
		{  
			s.push(exp[i]); 
			continue; 
		} 

		if (s.empty()) 
			return false; 

		switch (exp[i]) { 
		case ')': 
			
			x = s.top(); 
			s.pop(); 
			if (x == '{' || x == '[') 
				return false; 
			break; 

		case '}': 

			x = s.top(); 
			s.pop(); 
			if (x == '(' || x == '[') 
				return false; 
			break; 

		case ']': 

			x = s.top(); 
			s.pop(); 
			if (x == '(' || x == '{') 
				return false; 
			break; 
		} 
	} 

	return (s.empty()); 
} 


int main(){

	string expression="[[][]{}}{][]]";
	string exp="[()]{}{[()()]()}";

	BalancedParanthesesChecker(expression)?(cout<<"Valid Parantheses"<<"\n"):(cout<<"Invalid Parantheses"<<"\n");
	BalancedParanthesesChecker(exp)?(cout<<"Valid Parantheses"<<"\n"):(cout<<"Invalid Parantheses"<<"\n");
		return 0;
}