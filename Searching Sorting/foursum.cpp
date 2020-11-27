#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
bool elementExists(int ele,vector <int> v,int k){
	int i;
	for(i=k+1;i<v.size();i++){
		if(v[i]==ele){
			return 1;
		}
	}
	return 0;
}
void fourSum(vector <int> v,int sum){
	int i,j,k;

	for(i=0;i<v.size();i++){
		for(j=i+1;j<v.size();j++){
			for(k=j+1;k<v.size();k++){
				int sumThree=v[i]+v[j]+v[k];
				int finalElement=sum-sumThree;	

				if(elementExists(finalElement,v,k)){
				cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<" "<<finalElement<<"$";
			}
			break;
			}
		}

	}
}
*/


void sumOfFour(vector <int> v,int sum){
	int i,j,l,r;

	for(i=0;i<v.size()-3;i++){
		for(j=0;j<v.size()-2;j++){

			l=j+1;
			r=v.size()-1;

			while(l<r){
				if(v[i]+v[j]+v[l]+v[r]==sum){
					cout<<v[i]<<" "<<v[j]<<" "<<v[l]<<" "<<v[r]<<" $\n";
					l++;
					r--;
				}
				else if(v[i]+v[j]+v[l]+v[r]<sum){
					l++;
				}
				else{
					r--;
				}
			}
		}
	}
}


int main(){
	
	vector <int> v;
	v={10,2,3,4,5,7,8};
	sort(v.begin(),v.end());

	int sum=23;
	
	sumOfFour(v,sum);


	return 0;
}