#include <iostream>
#include <vector>
using namespace std;
/*
Rohan was going on a long vacation across various cities in the world. He had made an itinerary containing all the information 
about his journey. He had flight tickets booked as well.
Unfortunately, at the last minute, someone just ran into him and all his tickets fell on the floor.
Help him to find the correct order of all the tickets by finding the correct path from source to destination.


Example Input:

3

DEL KOL

MAA DEL

KOL GOA

Example Output:

MAA DEL KOL GOA

*/

string traverse(vector <pair<string,string>> v,string first){
    int i;
    for(i=0;i<v.size();i++){
        if(v[i].first==first){
             return v[i].second;
        }
    }
   return "-1";
}

vector <string> traverseAll(vector <pair<string,string>> v,string first){
    int i;
    int count=1;
    int k=v.size()+1;
    vector <string> vec;
    vec.push_back(first);
    string f;
    f=traverse(v,first);
    while(k--){
        if(f!="-1"){
        vec.push_back(f);
        }
        
        f=traverse(v,f);
    }
    return vec;
}

void printVector(vector <string> vec){
    int i;
    for(i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}

int main(){
    
    vector <pair<string,string>> v;
    int i,n;
    cin>>n;
    
    for(i=0;i<n;i++){
        string from,to;
        cin>>from>>to;
        v.push_back(make_pair(from,to));
    }

    int l=(v.size())+1;
    for(i=0;i<v.size();i++){
        vector <string> vec=traverseAll(v,v[i].first);
        if(vec.size()==l){
            printVector(vec);
        }
    }
   
    return 0;
}