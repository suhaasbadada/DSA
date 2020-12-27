#include <iostream>
#include <math.h>
using namespace std;

int numberOfFactors(int num){
    int i;
    int count=2;
    for(i=2;i<num;i++){
        if(num%i==0){
            count++;
        }
    }
    return count;
}
/*
An integer n is said to be the divisor of another integer m if m leaves a remainder 0 when divided by n.
We define a function : d(N) which is the number of pairs  (a,b) such that, a<b,  a*b=N and both the integers a and b 
have the same number of divisors.     For 24, we can have the pairs : (2,12), (3,8),(4,6), (1,24),(8,3).  
Here in any of the pair, the number of divisors of both the integers in a pair is not the  same. Hence, d(24)=0. 
For 48, the pairs are : (3,16),(2,24),  (4,12) , (1,48)and (6,8). Here the pair (6,8) is a pair such that both 6 and 8 have 4 divisors.
That is, (6,8) is a pair in which both the integers have same number of divisors. Other pairs of 48, do not have this property.
Hence d(48)=1.

Given a positive integer N, Write a code to compute the value of d(N).  For a given number N, if no pairs  (a,b) such that a<b, a*b=N, 
are possible, your code should output -1
*/
void funOfN(int n){
    int i,fcount=0,flag=0;
    for(i=2;i<sqrt(n);i++){
        if(n%i==0){
            flag=1;
            if(numberOfFactors(i)==numberOfFactors(n/i)){
                fcount++;
            }
        }
    }
    
    (flag==1)?(cout<<fcount):(cout<<-1);    
}


int main(){
    int i,n;
    cin>>n;
    
    funOfN(n);

    return 0;
}
