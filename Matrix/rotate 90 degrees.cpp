#include <bits/stdc++.h>
using namespace std;

#define size 4

void transpose(int arr[size][size]){
	int i,j;
	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			swap(arr[i][j],arr[j][i]);
		}
	}
}

void Clockwise90(int arr[size][size]){	//inplace
	int i,j;

	for(i=0;i<size/2;i++){
		for(j=0;j<size;j++){
			swap(arr[j][i],arr[j][size-i-1]);
		}
	}
}

void Anticlockwise90(int arr[size][size]){
	int i,j;

	for(j=0;j<size;j++){
		for(i=0;i<size/2;i++){
			swap(arr[i][j],arr[size-i-1][j]);
		}
		cout<<"\n";
	}
}

void printMatrix(int arr[size][size])
{
    for (int i = 0; i <size; i++) {
        for (int j = 0; j <size; j++)
            cout << arr[i][j] << "\t\t";
        cout <<"\n\n";
    }
}


int main()
{

    int arr[size][size] = {{ 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12},{ 13, 14, 15, 16 }};
    
    cout<<"Original Matrix:\n\n";
    printMatrix(arr);
    cout<<"\n";

    transpose(arr);
    cout<<"Transpose Matrix:\n\n";
    printMatrix(arr);
    cout<<"\n";
    
    Clockwise90(arr);
    cout<<"Clockwise Rotation 90°:\n\n";
    printMatrix(arr);
    cout<<"\n";
  
    //Anticlockwise90(arr);
    //cout<<"Anticlockwise Rotation 90°:\n\n";
    //printMatrix(arr);
    //cout<<"\n";
    
    return 0;
}


/*

MATRIX

1	2	3	4
5	6	7	8
9	10	11	12
13	14	15	16

TRANSPOSE

1 	5	 9	 13 
2	6	 10	 14 
3	7	 11	 15 
4	8	 12	 16

CLOCKWISE OF MATRIX 
we have to swap columns of transpose 

13 	9	5	1 
14 	10 	6	2 
15  11 	7	3 
16	12	8	4		


ANTICLOCKWISE OF MATRIX
we have to swap rows of transpose

4	 8	 12	 16 
3	 7	 11	 15 
2	 6	 10	 14 
1	 5	 9	 13 

*/