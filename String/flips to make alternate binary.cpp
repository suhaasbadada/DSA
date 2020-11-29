#include <iostream>
using namespace std;

char complement(char c){

	if(c=='0'){
		return '1';
	}else{
		return '0';
	}
}

void flip(string s,int start){
	int i;
	int flips=0;
	for(i=1;i<s.length();i++){
		if(i%2==0){
			if(s[i]==start){
				continue;
			}else{
				flips++;
			}
		}else{
			if(s[i]==start){
				flips++;
			}else{
				continue;
			}
		}
	}
	cout<<flips;
}


int main(){
	string str = "0001010111"; 
	int start=str[0];
	flip(str,start);
	return 0;
}