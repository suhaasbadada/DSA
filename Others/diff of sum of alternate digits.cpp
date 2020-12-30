#include <iostream>
using namespace std;

int altdiff(int n){
    int count=0;
    int r,se=0,so=0;
    
    while(n!=0){
        r=n%10;
        if(count%2==0){
            se+=r;
        }else{
            so+=r;
        }

        n/=10;
        count++;
        
    }
    return abs(se-so);
}

int main(){
    int n;
    cin>>n;
    
    cout<<altdiff(n);
    
    
    return 0;
}