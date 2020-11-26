#include <iostream>
using namespace std;

void subsequences(string s,int pos){
	int i,j;
	string z="";
	for(i=pos;i<s.length();i++){
		z+=s[i];
		cout<<z<<"\n";

	}

}

int main(){

	string s="aabc";
	int i;
	for(i=0;i<s.length();i++){
		subsequences(s,i);
	}

	return 0;
}