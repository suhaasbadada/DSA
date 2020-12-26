#include <iostream>
#include <sstream>  
#include <string>
using namespace std;
/*
With the help of the following procedure, every word is represented as an integer with even number of digits and an integer with 
even number of digits,  is represented as a word, 
Every symbol, A to Z is represented by the integers from 01 to 26 and vice versa. . The symbols from 'a' to 'z' is represented by the
integers , from 27 to 52  A represents 01, B represents 02, and so on. Z represents 26.  Similarly  'a' represents 27, 'b' represents 
28 and so on. z represents 52. The word  `abc' is represented by the intger 272829. Every symbol in `abc' is replaced by the respective 
integers.  `AbC' is represented by the integer 012803.  Note that the integer 012803 is not the same as the integer 12803.  

By the following procedure, any  positive integer with even number of digits is represented as  a word ,Every two successive digits, 
from the left (or right)  are replaced by the respective  symbols.   27 is replaced by 'a', 01 is replaced by 'A', 26 is replaced by 'Z'.  
If the successive digits, treated as a 2-digit integer , is greater than 52, that 2-digit intger is replaced by the word  that represents 
the number that equals 2-digit integer mod 52.

57 mod 52 =05.  Hence, 57 is replaced by the word that corresponds to 05.  57 is replaced by E.
By the above procedures, every word is represented as a positive integer with even number of digits and vice versa.
234501 is represented by WsA.  043131422749273835 represents the word 'Deepawali'.  Diwali is represented  by the integer 043549273835.
A word  'W' and an integer 'N'  (with even number of digits)  is said to be a perfect match if the intger representation of the word 'W'
is equal to the integer N. In that case, the first two digits (from the left) correspond to the first symbold of the word.  
The third and fourth digits, treated as a 2-digit integer corresponds to second symbol of the word and so on.  If 'W' and 'N' are a 
perfect match, all the succesive 2-digits of N is mapped  correctly, to the successive symbols of W.  In that case, the matching index of W and N is equal to the length of the word.
The integer 234501 perfectly matches with the word  WsA  and the matching index of 234501 & WsA is 3. 
All the three successive 2-digits of the integer  maps correctly to the three symbols of WsA.

The integer 234501 does not perfectly match with  WsB , since the digit 01 does not match correclty  to the symbol 'B' and 
the other symbols match correctly with the respective 2-digits.  In that case , matching index of 234501 & WsB is 2.
Similarly,The matching index of 234501 & WtB is one, since the symbols 't' and 'B' do not match correctly.

The matching index of 234501 & XtB is 0, since none of the symbols of the word do not match correctly with the respective integers.
Given a word W & an integer N (with even number of digits), matching index of W & N is the number of symbols of W that match correctly 
with the respective 2-digits of N .  

Given a word W and an integer N(with even number of digits), write a code to compute the matching index of W & N. 
If the number of digits in N is not equal to twice the number of symbols in W,    your program should output -1.
*/

int ascii(char ch){
    return ch;
}

string convertString(int num){
    ostringstream oss;
    oss<<num;
    string k=oss.str();
    return k;
}

string transform(string s){
    string z="";
    int i;
    
    for(i=0;i<s.length();i++){
        int asc=ascii(s[i]);
        if(asc>=65&&asc<=90){
            asc=asc-64;
            if(asc<10){
                z+='0';
            }
            z+=convertString(asc);
        }else if(asc>=97&&asc<=122){
            asc=asc-70;
            if(asc<10){
                z+='0';
            }
            z+=convertString(asc);
        }
    }
    return z;
}

string cleaning(string s){
    int i,num;
    string z;
    if(s.length()%2!=0){
        return "-1";
    }
    for(i=0;i<s.length();i+=2){
        num=(((int)s[i]-48)*10)+((int)s[i+1]-48);
        if(num>52){
            num=num%52;
            if(num<10){
                z+='0';
                z+=convertString(num);
            }
        }else{
            if(num<10){
                z+='0';
                z+=convertString(num);
            }else{
                z+=convertString(num);
            }
        }
    }
    return z;
}

int main(){
    string n,w;
    cin>>n>>w;
    // a-97 z-122 A-65 Z-90
    // A-01 Z-26 a-27 z-52
    w=transform(w);
    n=cleaning(n);
   
    if(n=="-1"){
        cout<<-1;
    }else{
        int i,count=0;
        for(i=0;i<n.length();i+=2){
            if(w[i]==n[i]&&w[i+1]==n[i+1]){
            count++;
        }
        
        }
      cout<<count<<"\n";   
    }
    
  
    
    return 0;
}