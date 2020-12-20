#include <iostream>
#include <vector>
using namespace std;

/*
A communication company transmits two series of integers S1 and S2 from one city to the other.
During the transmission the series S2 got corrupted. The company deleted the orginal data after transmission but they have the
XOR (S1,S2) which contains the XOR values of the corressponding eleements of S1 and S2. Interesting fact about XOR operation is 
if a XOR b = c then a XOR c = b and b XOR c = a. Given the number of integers ‘n’ in the series S1 and S2, elements of the series 
S1 and S2 at the recieving end, XOR(S1, S2), write a C program to find the original elements of s2 and the sum of errors in the
transmission. For example, if five integers were transmitted and the series S1 and S2 at the receiving end are

S1 - 17, 29, 35, 48, 93

S2 – 45, 67, 108, 34, 56

and the XOR (S1, S2) is

59, 96, 75, 23, 103

Then the orginal S2 series is

42, 125, 104, 39, 58

and the sum of error is 72
*/
void xorError(vector <int> s1,vector <int> s2,vector <int> vxor,int n){
    int i,og,error=0;
    for(i=0;i<n;i++){
        og=(vxor[i]^s1[i]);
        error+=abs(s2[i]-og);
        cout<<og<<"\n";
    }
    cout<<error;
}

int main(){
    int i,n;
    cin>>n;
    vector <int> s1;
    vector <int> s2;
    vector <int> vxor;
    
    for(i=0;i<n;i++){
        int data;
        cin>>data;
        s1.push_back(data);
    }
    
    for(i=0;i<n;i++){
        int data;
        cin>>data;
        s2.push_back(data);
    }
    
    for(i=0;i<n;i++){
        int data;
        cin>>data;
        vxor.push_back(data);
    }
    
    xorError(s1,s2,vxor,n);
    
    
    
    return 0;
}