/*
All of his classmates are divided into 'N' groups. Cabs are going to be ordered depending on the number of students.
The classmates which belong to the same group have to travel together. Each cab can carry at most 4 students. What is the minimum 
the number of cabs needed if all classmates of each group should travel in the same car and one car can take more than one group.
*/
#include <iostream>
using namespace std;

int counts(int arr[],int n,int p){
    int i;
    int count=0;
    for(i=0;i<n;i++){
        if(arr[i]==p){
            count++;
        }
    }
    return count;
}

int minCabs(int c1,int c2,int c3,int c4){
        
    int cabs=c4+c3+c2/2;
    
    c1-=c3; // since (1,3) form a pair
    
    if(c2%2==1){
        cabs+=1;
        c1-=2;  // (1,1,2) is a pair
    }
    
    if(c1>0){
        cabs+=(c1+3)/4;
    }
    
    return cabs;
}



int main(){
    
    int n,i;
    cin>>n;
    
    int arr[n];
    int s=0;
    for(i=0;i<n;i++){
        int g;
        cin>>g;
        s+=g;
        arr[i]=g;   
    }
    n=sizeof(arr)/sizeof(arr[0]); 
       
    int c1=counts(arr,n,1);
    int c2=counts(arr,n,2);
    int c3=counts(arr,n,3);
    int c4=counts(arr,n,4);
    

    cout<<minCabs(c1,c2,c3,c4);
    
    return 0;
}

