#include <iostream>
using namespace std;

int parathasMade(int r,int t){
    
    int i;
    
    int parathaCount=0;

    int s=0;    
    for(i=1;i<=t;i++){
        s+=r*i;
        if(s<=t){
            parathaCount++;
        }
    }
    
    return parathaCount;   
    
}

int totalParathas(int ranks[],int n,int t){
    int i;
    int totalParathas=0;
    for(i=0;i<n;i++){
        totalParathas+=parathasMade(ranks[i],t);
    }    
    return totalParathas;
}


int binaryParathaTime(int p,int ranks[],int n){
    int low=0;
    int high=10000007;
    int mid;
    int time=-1;

    while(low<=high){

        mid=(low+high)/2;
        if(totalParathas(ranks,n,mid)>=p){
            time=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return time;

}


int main(){
    
    int ranks[]={8,8,8};
    int n=sizeof(ranks)/sizeof(ranks[0]);
    int p=20;

    cout<<binaryParathaTime(p,ranks,n)<<"\n";
    
    
    return 0;
}