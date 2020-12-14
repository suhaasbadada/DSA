#include <iostream>
#include <vector>
using namespace std;

/*
A proper factor of a number is a factor of the number other than itself. Given a collection of numbers, a number n1 in position 
‘i’ is said to be principal number if the largest proper factor of all numbers in position > i is lesser than or equal to the largest 
proper factor of n1. The last number in the collection is a principal number. For example, given five numbers 29, 15, 5, 9 and 11, 
the output should be 15, 9 and 11.


*/

int largestFactor(int num){
    int i;
    for(i=num-1;i>0;i--){
        if(num%i==0){
            return i;
        }
    }
    return 0;
}

void printSequence(vector <int> v){
    int i,j;
    for(i=0;i<v.size();i++){
        int f=1;
        for(j=i+1;j<v.size();j++){
            if(largestFactor(v[i])<largestFactor(v[j])){
                f=0;
                break;
            }
        }
        if(f==1){
            cout<<v[i]<<"\n";
        }    
   }
}

int main(){
    
    int i,j,n;
    cin>>n;
    vector <int> v;
    for(i=0;i<n;i++){
        int nums;
        cin>>nums;
        v.push_back(nums);
    }
    
    printSequence(v);   
   
    return 0;
}