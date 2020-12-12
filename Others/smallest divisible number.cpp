#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
/*
Given an integer ‘n’ where n>=1, write a C code to check whether there exist a smallest number ‘S’, where S<=107 and S is 
divisible by all even numbers ‘m’ where 1<=m<=n.
For example, when n = 10, the smallest number divisible by all even numbers 2, 4, 6, 8 and 10 is 120. 
If no such number exist then print ‘No such number in range’.
*/
typedef long long int ll; 

int gcd(int a, int b) 
{ 
    if (b==0) 
        return a;
        
    return gcd(b,a%b); 
} 

ll findlcm(vector <int> v) 
{ 
    ll lcm = v[0]; 

    for (int i=1;i<v.size();i++) 
        lcm=(((v[i]*lcm))/(gcd(v[i],lcm))); 
  
    return lcm; 
} 
int main(){
    int i,n;
    cin>>n;
    vector <int> v;
    for(i=2;i<=n;i+=2){
        v.push_back(i);
    }
    
    (findlcm(v)>pow(10,7))?(cout<<"No such number in range"):(cout<<findlcm(v));
    
    return 0;
}