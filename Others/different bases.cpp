#include <iostream>
#include <cmath>
using namespace std;

/*
Given a number and a base, convert the number to armstrong number
convert this converted number to the given base b, and check if it equals n.

Given a number ‘n’ and a base ‘b’, write a code to check if n is a special with respect to base ‘b’.
If any digit of ‘n’ is greater than ‘b-1’ then print ‘Invalid’.
Example 1:

Input

122

3

Output

Yes

Explanation

122 -> number of digits - 3

1^3 + 2^3 + 2^3 -> 17

17 to base 10 is 122 to base 3

Example 2:

Input

433

5

Output

Yes

Example 3:

Input

121

3

Output

No

Example 4:

Input

125

3

Output

Invalid
*/
int PowerDecimal(int n,int b){
    int length=0;
    int n1=n;
    while(n1>0){
        if(n1%10>=b){
            return -1;
        }
        length++;
        n1/=10;
    }
    
    int n2=n;
    int converted=0;
    while(n2>0){
        int r=n2%10;
        converted+=pow(r,length);
        n2/=10;
    }
    
    return converted;
   
}

void convertThis(int n,int checkThis,int b){
    if(checkThis==-1){
        cout<<"Invalid";
    }else{
        int r;
        int reversed=0;
        int count=0;
        while(checkThis>0){
            r=checkThis%b;
            reversed+=r*pow(10,count); 
            checkThis/=b;
            count++;
        }
       if(reversed==n){
           cout<<"Yes";
       }else{
           cout<<"No";
       }
    }      
}



int main(){
    int n,b;
    cin>>n>>b;
    int checkThis=PowerDecimal(n,b);
    convertThis(n,checkThis,b);
    
    return 0;
}