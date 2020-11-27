#include <iostream>
#include <iterator> 
#include <unordered_map>
using namespace std;

#define rows 4 
#define cols 5 

void printMap(unordered_map<int, int> map){
	 
	  for (auto i : map) 
        cout << i.first << "   " << i.second<< endl; 
  
} 


void commonElements(int mat[rows][cols]){
	unordered_map<int, int> map; 
	
	int i,j;

	for(j=0;j<cols;j++){
		map[mat[0][j]]=1;
	}

	//printMap(map);

	cout<<"\n\n";

	for(i=1;i<rows;i++){
		for(j=0;j<cols;j++){
			if(map[mat[i][j]]==i){
				map[mat[i][j]]=i+1;

				if(i==rows-1){
					cout<<mat[i][j]<<" ";
				}
			}
		}
	}

	//printMap(map);

}





int main(){
	int mat[rows][cols]={{1, 2, 1, 4, 8},{3, 7, 8, 5, 1},{8, 7, 7, 3, 1},{8, 1, 2, 7, 9}}; 
  	
  	commonElements(mat);


	return 0;
}