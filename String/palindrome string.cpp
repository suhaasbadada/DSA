#include <iostream>
using namespace std;

void palindrome(string s){
	int i;
	int flag=1;
	for(i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<"palindrome"<<"\n";
	}else{
		cout<<"not a palindrome"<<"\n";
	}
}

int main(){

	string s="geeksforgeeks";
	palindrome(s);

	return 0;
}