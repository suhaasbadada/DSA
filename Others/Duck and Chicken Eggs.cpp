#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
A farmers takes chicken and duck eggs in ‘n’ baskets. 
In two baskets he has got duck eggs and rest of the bags he has chicken eggs. 
Number of eggs in each basket is distinct. He tells that number of chicken eggs is twice as that of number of duck eggs. 
Given the name of the ‘n’ baskets and number of eggs in them, write a code to print the name of baskets with duck eggs 
and name of basket with chicken eggs.If there can be more than one combination in which duck eggs can be there, 
consider the first basket name which comes first in the input order

Input

5

B1 5

B2 12

B3 14

B4 23

B5 6

Output

B3 B5

B1 B2 B4
*/

void printVector(vector <string> v){
    int i;
    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void printBaskets(vector <string> vb,vector <int> ve,int sc,int sd){
    int i,j;
    for(i=0;i<ve.size();i++){
        for(j=i+1;j<ve.size();j++){
          int s_c=accumulate(ve.begin(),ve.end(),0)-(ve[i]+ve[j]);
         if(ve[i]+ve[j]==sd && s_c==sc){
            cout<<vb[i]<<" "<<vb[j]<<"\n";
             ve.erase(ve.begin()+i);
             ve.erase(ve.begin()+j-1);
             vb.erase(vb.begin()+i);
             vb.erase(vb.begin()+j-1);
             printVector(vb);
         }
            
        }
        
    }
}

int main(){
    int i,j,n;
    cin>>n;
    vector <string> vb;
    vector <int> ve;
    
    for(i=0;i<n;i++){
        int eggs;
        string basket;
        cin>>basket>>eggs;
        vb.push_back(basket);
        ve.push_back(eggs);
       
    }
    int s=0;   
    for(i=0;i<ve.size();i++){
        s+=ve[i];
    }
    int sc=2*s/3;
    int sd=s/3;
    
    printBaskets(vb,ve,sc,sd);
  
    return 0;
}