/*
Given a size the board, p, initial cell of the coin in the board, a list of movements and a winning cell in the board, 
write a code to check if the coin reaches the winning cell from initial cell by these movements. 
If the winning position is reached then print Win and print Loss otherwise.

left,right,up,down

5
2 1
4
l
r
r
u
3 2
*/

#include <iostream>
#include <vector>
using namespace std;

bool moves(vector <char> v,int n,int i_x,int i_y,int f_x,int f_y){
    for(int i=0;i<v.size();i++){
       switch(v[i]){
           case 'l':
               if(i_y>0){
                i_y-=1;
               }
            break;
           
           case 'r':
               if(i_y<n-1){
                   i_y+=1;
               }
           break;
           
           case 'u':
               if(i_x<n-1){
                   i_x+=1;
               }
           break;
           
           case 'd':
               if(i_x>0){
                   i_x-=1;
               }
           break;
       }
        
    }
    return (i_x==f_x && i_y==f_y);
}

int main(){
    int i,n;
    int i_x,i_y;
    int m;
    cin>>n>>i_x>>i_y>>m;
    vector <char> v;
    for(i=0;i<m;i++){
        char moves;
        cin>>moves;
        v.push_back(moves);
    }
    int f_x,f_y;
    cin>>f_x>>f_y;

    cout<<moves(v,n,i_x,i_y,f_x,f_y);
    
    return 0;
}