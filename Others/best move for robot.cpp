#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
/*
In an industry, robots are employed to bring specified number of nuts, ‘n’ to its current location. 
Different numbers of nuts are packed in ‘m’ packages and kept in a rack at a location inside the industry.

Robot can make only one fetch operation. In a single fetch operation, they can fetch packages from one rack or more than one adjacent racks 
only. Size of the fetch operation is the number of packages taken by the robot. 
Power consumed by the robot increases with the size of the fetch operation. When fetch size is same, fetching from rack(s) with lesser rack 
numbers consume less power than fetching from higher rack numbers.

Given the number of nuts required, ‘n’ and the number of nuts in each of ‘m’ packages, write a code to print the number of nuts in the
packages that are to be taken by the robot so that it consumes least possible power.
If the number of nuts cannot be fetched by the robot print ‘Not possible’.


Input
15
5
2 3 6 4 5

Output
6 4 5
*/

void printVector(vector <int> v){
    int i;
    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void NutsFetched(vector <int> v,int n){
    int i,j;
    int currSum;
    int fetchSize;
    vector <int> vf;
    map <int,vector <int>> m;
    
    for(i=0;i<v.size();i++){
        currSum=0;
        vf.clear();
        for(j=i;j<v.size();j++){
            currSum+=v[j];
            if(currSum<=n){
                vf.push_back(v[j]);
            }
        }
        int cumsum=(accumulate(vf.begin(),vf.end(),0));
        int fetchSize=vf.size();
        if(cumsum==n){
            m[fetchSize]=vf;
        }
    }
    
    if(m.begin()->first==0){
         cout<<"Not possible";
    }else{
        printVector(m.begin()->second);
    }
      
}


int main(){
    int i,n,m;
    cin>>n>>m;
    vector <int> v;
    for(i=0;i<m;i++){
        int nuts;
        cin>>nuts;
        v.push_back(nuts);
    }
    
    NutsFetched(v,n);
    
    return 0;
}