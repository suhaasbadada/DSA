#include <iostream>
using namespace std;

void reverse(string s[],int l){
	int i;
	for(i=0;i<l/2;i++){
		string temp=s[i];
		s[i]=s[l-i-1];
		s[l-1-i]=temp;
	}

}


int main(){
	
	string s[]={"h","e","l","l","o","\0"};

	int i,l=0;
	for(i=0;s[i]!="\0";i++){
		l++;
	}

	reverse(s,l);
	for(i=0;s[i]!="\0";i++){
		cout<<s[i]<<"";
	}



	return 0;
}