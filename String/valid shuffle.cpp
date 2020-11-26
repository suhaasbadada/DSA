#include <iostream>
using namespace std;

bool isOrderMaintained(string s,string shuffled){
	int i=0,j=0,count=0;

	while(i!=shuffled.length()){			
		if(j!=s.length()){			
			if(shuffled[i]==s[j]){
				j++;
				count++;				
			}else{
				i++;
			}			
		}

		if(count==s.length()){
			return true;
		}
	}

	return false;
}

void isValid(string s1,string s2,string s3){
	bool a=isOrderMaintained(s1,s3);
	bool b=isOrderMaintained(s2,s3);

	if(a && b){
		cout<<"Valid Shuffle"<<"\n";
	}else{
		cout<<"Invalid Shuffle"<<"\n";
	}
}



int main(){

	string s1,s2,s3,s4,s5,s6,s7,s8;
	s1="XY";
	s2="12";
	s3="1XY2";
	s4="Y12X";

	s5="abc";
	s6="def";
	s7="dabcef";
	s8="dcebfa";

	isValid(s1,s2,s3);
	isValid(s1,s2,s4);

	isValid(s5,s6,s7);
	isValid(s5,s6,s8);



	return 0;
}