#include <iostream>
using namespace std;

int woodCutLength(int arr[],int n,int sawLength){
    int i;
    int lengthCut=0;
    for(i=0;i<n;i++){
        if(arr[i]>sawLength){
            lengthCut+=(arr[i]-sawLength);
        }
    }
    return lengthCut;
}

int arrMax(int arr[],int n){
    int max=arr[0];
    int i;
    for(i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

// the lengths decrease with increasing values of i
int sawBinarySearch(int arr[],int n,int max,int ecoCutLength){
    int low=0;
    int high=max;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        if(ecoCutLength==(woodCutLength(arr,n,mid))){
            high=mid;
            break;
        }
        
        else if((woodCutLength(arr,n,mid))>ecoCutLength){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    
    }
    return high;
}


int main(){
    
    int arr[]={4,42,40,26,46};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ecoCutLength=20;
    int max=arrMax(arr,n);
    
    cout<<sawBinarySearch(arr,n,max,ecoCutLength)<<"\n";
    

    /*
    int i;
    for(i=0;i<=20;i++){
        cout<<woodCutLength(arr,n,i)<<"\n";
    }
    */
    
    return 0;
}
