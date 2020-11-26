#include <bits/stdc++.h>
using namespace std;

void TraditionalMethodTriplets(int arr[],int n,int sum){
	int i,j,k;

	for(i=0;i<n;i++){
		int currSum=0;
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				if(arr[i]+arr[j]+arr[k]<sum){
					cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"\n";
				}
			}
		}
	}
}

int CountOfTriplets(int arr[],int n,int sum){
	sort(arr,arr+n);
	int count=0;

	int i,j,k;
	for(i=0;i<n-2;i++){
		
		j=i+1;
		k=n-1;

		while(j<k){
			if(arr[i]+arr[j]+arr[k]>=sum){
				k--;
			}else{
				count+=(k-j);
				j++;
			}
		}
	}
	return count;
}




int main(){
	
	int arr[]={5,1,3,4,7}; 
    int n=sizeof(arr)/sizeof(arr[0]); 
    int sum=12;

    
    //TraditionalMethodTriplets(arr,n,sum);

    //{1,3,4,5,7}
    cout<<CountOfTriplets(arr,n,sum)<<"\n"; 	



	return 0;
}