#include <iostream>
#include <vector>
using namespace std;

#define R 4
#define C 4

/*
// BASE LOGIC
void Loop(int mat[R][C],int rows,int cols){
	int right,down,left,up;
	int i,j;

	//right
	for(j=0;j<cols;j++){
		cout<<mat[0][j]<<"\t";
	}

	//down
	for(i=1;i<rows;i++){
		cout<<mat[i][cols-1]<<"\t";
	}

	//left
	for(j=cols-2;j>=0;j--){
		cout<<mat[rows-1][j]<<"\t";
	}

	//up
	for(i=rows-2;i>0;i--){
		cout<<mat[i][0]<<"\t";
	}

}
*/

void SpiralTraversal(int mat[R][C],int r,int c){
	int i,j,k=0,l=0;
	
	/* k - starting row index
       l - starting column index
    */

	while(k<r && l<c){

		//right
			for(j=l;j<c;++j){
				cout<<mat[k][j]<<" ";
			}
			k++;

		//down
			for(i=k;i<r;++i){
				cout<<mat[i][c-1]<<" ";
			}
			c--;

		//left
		if(k<r){
			for(j=c-1;j>=l;--j){
				cout<<mat[r-1][j]<<" ";
			}
			r--;
		}

		//up
		if(l<c){
			for(i=r-1;i>=k;i--){
				cout<<mat[i][l]<<" ";
			}
			l++;
		}

	}

}



int main(){

	int mat[R][C]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int r=R;
	int c=C;
	//Loop(mat,r,c);
	SpiralTraversal(mat,r,c);

	/*
	1	2	3	4
	5	6	7	8
	9	10	11	12
	13	14	15	16

	We can store elements in a vector/queue for spiral traversed order
	and stack for antispiral order
	*/
	return 0;
}