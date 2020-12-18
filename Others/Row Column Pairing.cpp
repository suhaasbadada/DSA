#include <iostream>
#include <vector>
using namespace std;

/*
Given two matrices m1 , m2 and a capacity 'C', write a code to obtain a matrix m3 after row-column pairing. 
Row - column paring is an operation in which the elements in the matrix1 are paired rowwise with elements of matrix2 columnwise 
to obtain a matrix m3. m3[i][j] is the count of elements of ith row when added with corressponding (column index of element in matrix1 
is same as row index of element in matrix2) elements of jth column is less than or equal to capacity C.

For example, given a matrix m1 as below:

120 230 170 110

100 90 115 190

135 78 95 245

and m2 as below:

300 400 240 450

456 230 245 350

236 230 340 234

392 321 295 331

when capacity is 500, matrix m3 will be:

2 3 3 2

2 2 4 2

2 2 3 2

( each row of M1 is added with every column of M2  )

*/

void RowColPairCount( vector<vector<int>> v1, vector<vector<int>> v2,int capacity,int ind){
    int c1=v1[0].size();
    int r2=v2.size();
    int c2=v2[0].size();
    int i,count,counter=0;
    
    while(counter<c2){
        count=0;
        for(i=0;i<r2;i++){
            int val=v1[ind][i]+v2[i][counter];
            if(val<=capacity){
                    count++;
            }
        }
        cout<<count<<"\t";
        
        counter++;
    }
    
    cout<<"\n";
}


int main(){
   
    int r1,r2;
    int c1,c2;
    cin>>r1>>c1;
    int i,j;
    vector<vector<int>> v1(r1,vector<int> (c1));
    
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            int cells;
            cin>>cells;
            v1[i][j]=cells;
        }
    }
    
    cin>>r2>>c2;
    vector<vector<int>> v2(r2,vector<int> (c2));
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            int cells;
            cin>>cells;
            v2[i][j]=cells;
        }
    }
    int capacity;
    cin>>capacity;
    
    int ind;
    
    for(ind=0;ind<r1;ind++){
        RowColPairCount(v1,v2,capacity,ind);
    }
    
    return 0;
}
