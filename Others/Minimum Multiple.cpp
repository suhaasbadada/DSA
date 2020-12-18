#include <iostream>
#include <climits>
#include <vector>
using namespace std;
/*
Given a collection C1 of ‘n’ positive integers and a number ‘m’ write a C program to find the minimum multiple of m in C1. 
If no such multiple exist in C1 then print ‘No multiple found’

For example, if there are seven elements 23, 24, 25, 12, 6, 7, 11 and m is 3 then the output should be 6.
*/
int MinMultiple(vector <int> v,int multiple){
    int i,min=INT_MAX;
    for(i=0;i<v.size();i++){
        if(v[i]%multiple==0){
            if(v[i]/multiple<min){
                min=v[i];
            }
        }
    }
    return min;
}

int main(){
    int i,n;
    cin>>n;
    vector <int> v;
    for(i=0;i<n;i++){
        int elements;
        cin>>elements;
        v.push_back(elements);
    }
    int multiple;
    cin>>multiple;
    
    int min=MinMultiple(v,multiple);
    
    (min==INT_MAX)?(cout<<"No multiple found"):(cout<<min);

    return 0;
}