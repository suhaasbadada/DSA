#include <iostream>
using namespace std;

// 1 11 21 1211 111221 .....................

string CountnSay(int n){
	if(n==1)
		return "1";
	if(n==2)
		return "11";

	int i;
	string s="11";

	for(i=3;i<=n;i++){
		s+='$';
		int len=s.length();
		int count=1;
		string temp="";
		int j;
		for(j=1;j<len;j++){
			if(s[j]!=s[j-1]){
				temp+=count+'0';	// adding 0 allows char conversion
				temp+=s[j-1];
				count=1;
			}else{
				count++;
			}
		}

		s=temp;
	}
	return s;
}

int main(){
	
	int i;
	/*
	for(i=1;i<10;i++){
		cout<<CountnSay(i)<<"\n";
	}*/
	
	cout<<CountnSay(5);
	
	return 0;
}