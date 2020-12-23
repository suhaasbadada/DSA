#include <iostream> 
#include <math.h>
using namespace std;
/*
Given area of a square,print the count of rectangles that can be formed with that area
The rectangles with the dimension l,b and the rectangle with the dimension b,l are considered as the same rectangle. 
*/

int main(){
    int i,n;
    cin>>n;
    
    int count=0;
    for(i=1;i<sqrt(n);i++){
        if(n%i==0){
            count++;
        }
    }
    cout<<count;
    
    return 0;
}