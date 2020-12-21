#include <iostream>
using namespace std;

/*
You are given a sequence of integers. You want to find out if all the numbers have a common divisor. 
Common divisor should be greater than 1.
If there exists such a number, print "YES", otherwise print "NO".
*/
int gcd(int a, int b)
{
    if (a==0){
        return b;
    }
    return gcd(b%a,a);
}
 
int main(){
    int i,n,f=1;
    int arr[n];
    
    for(i=0;i<n;i++){
        int vals;
        cin>>vals;
        arr[i]=vals;
    }
    
    int gc=gcd(arr[0],arr[1]);
    for(i=1;i<n;i++){
        gc=gcd(gc,arr[i]);
    }
    
    (gc>1)?(cout<<"YES"):(cout<<"NO");
    
    
    return 0;
}   