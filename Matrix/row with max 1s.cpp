#include <iostream>
using namespace std;
#define R 4  
#define C 4  

int main(){

	bool mat[R][C] = {{0, 0, 0, 1},{0, 1, 1, 1},{1, 1, 1, 1},{0, 0, 0, 0}};  

	int i;

	int Max1Row=0;
	int max1s=0;

	for(i=0;i<R;i++){

		int index=C;
		while((index-1)>=0 && mat[i][index-1]==1){
			--index;
		}

		if(max1s<R-index){
			max1s=R-index;
			Max1Row=i;
		}

	}
	cout<<Max1Row;

	return 0;
}
