#include <iostream>
using namespace std;

bool isRotated(string s1,string s2){

	if(s1.length()!=s2.length()){
		return false;
	}
	string s3=s1+s1;

	return (s3.find(s2) != string::npos);	//npos --> no position
	// string::npos holds greatest possible value for type string, here
	// .find returns the greatest possible value if the string is not found
}	

int main(){

	string s1="abacd";
	string s2="cdaba";

	isRotated(s1,s2)?(cout<<"Rotated Strings "<<"\n"):(cout<<"Independent Strings"<<"\n");
	// <condition> ? <true-case-code> : <false-case-code>; ternary operator
	return 0;
}