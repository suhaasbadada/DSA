#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Ramu makes a travel to one his office in a hilly region by his car. 
Given the height of his current location above sea level every few minutes after he starts the travel, write a code to check the 
number of up moves and down moves. First move is always up move.

For example, if 12 points are given as follows 45, 60, 82, 72, 65, 32, 53, 84, 103, 110, 89, 95 
then there are 3 up moves and 2 down moves as shown below:

             /\
      /\    /  \/ 
     /  \  /
         \/
There are 3 peaks and 2 pits

*/
void UpsDowns(vector <int> v){
    int i;
    int ups=0;
    int downs=0;
    for(i=0;i<v.size();i++){
        
        if(v[i]>v[i-1] && v[i]>v[i+1]){
            ups++;
        }
        
        if(v[i]<v[i-1] && v[i]<v[i+1]){
            downs++;
        }
    }
    
    if(v[v.size()-2]>v[v.size()-1]){
        downs++;
    }
    
    cout<<ups<<" "<<downs;
}

int main(){
    int i,n;
    cin>>n;
    
    vector <int> v;
    for(i=0;i<n;i++){
        int heights;
        cin>>heights;
        v.push_back(heights);
    }
    
    UpsDowns(v);
    
    return 0;
}