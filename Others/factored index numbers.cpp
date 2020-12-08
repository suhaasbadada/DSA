#include <iostream>
#include <vector>
using namespace std;

/*
A number ‘n’ in a list at index ‘i’ (human indexing) is said to be a factor indexed number if ‘i’ is a factor ‘n’. 
Given two lists of numbers l1 and l2 form a list l3 by inserting factor indexed numbers of l1 and l2. 
Intialize index to ‘0’ visit elements of l1 and l2 at index, if one of them is factored indexed insert and increment index and go 
till end of the list. If both of them are factor indexed then insert element of l1 at index and then element of l2 at index and increment 
ndex. If end of one of the list is reached then add elements of other list to l3 if they are factor indexed.
After construction of l3, Print the numbers which continues to be factor indexed in l3.

For example, if l1 contains 15, 12, 17, 32, 26, 42 and l2 contains 45, 34, 64, 80 then l3 will be 15, 45, 12, 34, 32, 80, 42 
then print 15, 12, 42.
*/

void printVector(vector <int> v){
    int i;
    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

vector <int> factoredIndex(vector <int> v1,int n1,vector <int> v2,int n2,vector <int> v3){
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(v1[i]%(i+1)==0){
            v3.push_back(v1[i]);
        }
        i++;
        if(v2[j]%(j+1)==0){
            v3.push_back(v2[j]);
        }
        j++;
    }
    // remaining
    while(i<n1){
        if(v1[i]%(i+1)==0){
            v3.push_back(v1[i]);
        }
        i++;
    }
    
    while(j<n2){
        if(v2[j]%(j+1)==0){
            v3.push_back(v2[j]);
        }
        j++;
    }
   return v3;
}

int main(){
    int i,n1,n2;
    cin>>n1;
    vector <int> v1;
    vector <int> v2;
    vector <int> v3;
    
    for(i=0;i<n1;i++){
        int ele;
        cin>>ele;
        v1.push_back(ele);
    }
    
    cin>>n2;
      
    for(i=0;i<n2;i++){
        int ele;
        cin>>ele;
        v2.push_back(ele);
    }
    
    v3=factoredIndex(v1,n1,v2,n2,v3);
    
    for(i=0;i<v3.size();i++){
        if(v3[i]%(i+1)==0){
            cout<<v3[i]<<"\n";
        }
    }
    
    
    return 0;
}