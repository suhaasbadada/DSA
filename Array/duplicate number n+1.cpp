#include <iostream>
#include <cstring>
using namespace std;




int main(){
	int arr[]={1,3,4,2,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int repeating[n+1]; 
    memset(repeating,0, sizeof(repeating)); 

    int i;
    for(i=0;i<n;i++){
    	repeating[arr[i]-1]+=1;
    }

    for(i=0;i<n;i++){
    	if(repeating[i]==2){
    		cout<<i+1<<"\n";
    	}
    }
	return 0;
}