#include <iostream>
using namespace std;



void binarySoldierDamage(int soldierPowers[],int n,int power){
	int low=0;
	int high=n;

	while(low<=high){
		int mid=(low+high)/2;

		if(soldierPowers[mid]==power){
			low=mid;
			break;
		}
		else if(soldierPowers[mid]>power){
			high=mid-1;
		}
		else{
			low=mid+1;
		}

	}


	int i,damage=0;
			for(i=0;i<low;i++){
			damage+=soldierPowers[i];
		}

		if(power>n){
			power=n;
		}

	cout<<power<<" "<<damage<<"\n";
}


int main(){

	int soldierPowers[]={1,2,3,4,5,6,7};

	int n=sizeof(soldierPowers)/sizeof(soldierPowers[0]);
	
	int powers[]={3,10,2};

	int m=sizeof(powers)/sizeof(powers[0]);

	int i;
	for(i=0;i<m;i++){
		binarySoldierDamage(soldierPowers,n,powers[i]);
	}
	
	
	return 0;
}