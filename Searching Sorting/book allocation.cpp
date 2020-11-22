#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int n,int students,int curr_min){
	int studentsReqd=1;
	int curr_sum=0,i;

	for(i=0;i<n;i++){
		if(arr[i]>curr_min){
			return false;
		}

		if(curr_sum+arr[i]>curr_min){
			
			studentsReqd++;
			curr_sum=arr[i];
		}

		if(studentsReqd>students){
			return false;
		}
		else{
			curr_sum+=arr[i];
		}
	}
	return true;
}


int findPagesBinary(int arr[],int n,int students){
	int sum=0,i;

	if(n<students){
		return -1;
	}

	for(i=0;i<n;i++){
		sum+=arr[i];
	}

	int low=arr[n-1];
	int high=sum;
	int result=INT_MAX;

	while(low<=high){
		int mid=(low+high)/2;

		if(isPossible(arr,n,students,mid)){
			result=min(result,mid);

			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	
	return result;
}



int main(){

	int pages[]={12, 34, 67, 90};
	int n=sizeof(pages)/sizeof(pages[0]);
	int students=2;

	cout<<findPagesBinary(pages,n,students)<<"\n";

	return 0;
}