#include <iostream>
using namespace std;

string PrefixbwTwo(string s1,string s2){
	string z="";
	int i,j;
	for(i=0,j=0;i<s1.length() && j<s2.length();i++,j++){
		if(s1[i]==s2[i]){
			z+=s1[i];
		}else{
			break;
		}
	}
	return z;
}

string longestPrefix(string arr[],int n){
	string prefix=arr[0];
	int i;
	for(i=1;i<n;i++){
		prefix=PrefixbwTwo(prefix,arr[i]);
	}
	return prefix;
}

int main(){
	string arr[] = {"geeksforgeeks","geeks","geek","geezer"}; 	
	int n=sizeof(arr)/sizeof(arr[0]);
	

	cout<<longestPrefix(arr,n);


	return 0;
}