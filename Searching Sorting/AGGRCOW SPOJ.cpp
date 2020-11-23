#include <iostream>
using namespace std;

bool isGapPossible(int stalls[],int n,int totalCows,int g){
	int cows=1;
	int i;
	int pos=stalls[0];

	for(i=0;i<n;i++){

		if(stalls[i]-pos>=g){
			pos=stalls[i];
			cows++;

			if(cows==totalCows){
				return 1;
			}
		}
	}
	return 0;
}

int binaryOnGap(int stalls[],int n,int totalCows){
	int low=0;
	int high=stalls[n-1];
	int result=-1;

	while(low<high){
		int mid=(low+high)/2;

		if(isGapPossible(stalls,n,totalCows,mid)==1){
			if (mid>result){
				result=mid;
			}
			low=mid+1;
		}
		else{
			high=mid;
		}
	}	
	return result;
}



int main(){

	int stalls[]={1,2,4,8,9};
	int n=sizeof(stalls)/sizeof(stalls[0]);
	int totalCows=3;

	cout<<binaryOnGap(stalls,n,totalCows)<<"\n";



	return 0;
}