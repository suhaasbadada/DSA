#include <iostream>
using namespace std;

int ascii(char c){
    return c;
}

void fillChars(string s,int count[]){
	int i;
	for(i=0;i<s.length();i++){
		count[ascii(s[i])-97]+=1;
	}
}

int main(){
	int i;
	string s="kwdldnvjdvnfhvbdcnjdcbdzbejhfvqeoifwouvqeuvbzz";
	int count[26]={0};	// array of 0s 
	//assuming string has only alphabets otherwise can change length to 256

	fillChars(s,count);

	for(i=0;i<26;i++){
		if(count[i]>1){
			cout<<(char)(i+97)<<" "<<count[i]<<"\n";
		}
	}	

	return 0;
}