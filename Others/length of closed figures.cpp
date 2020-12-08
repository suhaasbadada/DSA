#include <iostream>
#include <vector>
using namespace std;

/*
Two lines P1 and P2 are said to be connected if the end point of P1 and start point of P2 are same.
 In this problem, there is a collection of points in a two dimensional space and the point numbers are given to represent a line. 
 All the lines have distinct starting point and ending point. 
 Given the start and end point numbers of ‘n’ lines and a check point number ‘p’ write a code to find out the length 
 of the closed figure that can be formed that starts with the check point number ‘p’. 
 For example, given ten pairs of point numbers for 10 lines as follows:

 10
2 5
7 11
13 14
11 15
17 18
15 17
18 25
32 40
25 32
40 7
7
*/

int next(vector <int> x,vector <int> y,int iy){
    int i;
    for(i=0;i<x.size();i++){
        if(x[i]==iy){
            return y[i];
        }
    }
    return 0;
}




int main(){
    int n;
    cin>>n;
    int i;
    
    vector <int> x;
    vector <int> y;
    
    for(i=0;i<n;i++){
        int xcord,ycord;
        cin>>xcord;
        cin>>ycord;
        x.push_back(xcord);
        y.push_back(ycord);
    }
    int ix;
    cin>>ix;
    
    int iy;
    for(i=0;i<x.size();i++){
        if(y[i]==ix){
            iy=y[i];
            break;
        }
    }
    
    int store_y=iy;
    
    iy=next(x,y,iy);
    
    if(iy!=0){
    
    int length=1;
    while(iy!=store_y){

        iy=next(x,y,iy);
        length++;       
    }
    cout<<length;
    }else{
        cout<<0;
    }
        
    return 0;
}