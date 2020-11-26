#include <iostream>
using namespace std;

int EqualBinarySplit(string s){
	int i;
	int count0=0;
	int count1=0;
	int substrNum=0;
	string z="";

	for(i=0;i<s.length();i++){
		if(s[i]=='0'){
			count0++;
			z+=s[i];
		}else{
			count1++;
			z+=s[i];
		}
		if(count0==count1){
			substrNum++;
			cout<<z<<" ";
			z="";
		}		
	}

	if (count0!=count1) { 
        return -1; 
    } 
    cout<<"\n";
    return substrNum;
}



int main(){

	string binary="0100110101";

	cout<<EqualBinarySplit(binary)<<"\n";


	return 0;
}