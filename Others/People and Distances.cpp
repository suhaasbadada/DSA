#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
You are given the top view of a ground, where there are two values: '0' and '1'. Each '1' denotes that there is a person standing at that 
position in the ground. Recently Raman was asked to find the number of distinct pairs of people who have given manhattan distances between them.
Raman doesn't like to disappoint and hence he has come to you for help.

Input:
3 4
0001
0100
0010
5
1
2
3
4
5

Output:
0
1
2
0
0

the matrix given row wise in the form of a string
*/
vector<vector<int>> xy(string r,int k,vector<vector<int>> v){
    int j;
    
    for(j=0;j<r.length();j++){
        vector <int> cell;
        if(r[j]=='1'){
            cell.push_back(k);
            cell.push_back(j);
            v.push_back(cell);
        }
    }
    return v;
}

map <int,int> ManhattanDistance(vector<vector<int>> v,map<int,int> m){
    int i,j,manhattan;
    for(i=0;i<v.size();i++){
        for(j=i+1;j<v.size();j++){
            manhattan=abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1]);
            m[manhattan]++;
        }
    }
    return m;
}


int main(){
    int rows,cols;
    cin>>rows>>cols;
    int i,j;
    vector<vector<int>> v;
    map<int,int> m;
 
    for(i=0;i<rows;i++){
        string r;
        cin>>r;
        v=xy(r,i,v); 
    }
    
    m=ManhattanDistance(v,m);
    
    int tests;
    cin>>tests;
    for(i=0;i<tests;i++){
        int queries;
        cin>>queries;
        cout<<m[queries]<<"\n";
    }
    

    return 0;
}