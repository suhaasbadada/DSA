#include <iostream>
using namespace std;

void KeypadSequence(string numeric_keypad_sequence[],string input){

	int i;
	for(i=0;i<input.length();i++){
		if(input[i]==' '){
			cout<<'0';
		}else{
			
			int ascii;
			ascii=input[i];

			cout<<numeric_keypad_sequence[ascii-65];
		}
	}
}

int main(){
	string numeric_keypad_sequence[] =
	 				{"2","22","222", 
                    "3","33","333", 
                    "4","44","444", 
                    "5","55","555", 
                    "6","66","666", 
                    "7","77","777","7777", 
                    "8","88","888", 
                    "9","99","999","9999"
                   }; 

   	string s="GEEKS FOR GEEKS";


    KeypadSequence(numeric_keypad_sequence,s);

	return 0;
}