#include <bits/stdc++.h>
using namespace std;



// PRIORITY QUEUE

void kthmax(priority_queue<int> p,int n,int k){
	int count=0;


	while(p.size()>n-k)  
 	{  
 		count++;
	if (count==k){
		cout << p.top()<<" ";   
	}
     p.pop();       
 	}  
}

void kthmin(priority_queue<int> p,int n,int k){
	int count=0;

	while(p.size()>k)  
 	{  
 		count++;
	if (count==n-k){
		cout << p.top()<<" ";   
		p.pop();
	}
     p.pop();       
 	}  

}

int main(){


	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	priority_queue<int> p;

	int i;
	for(i=0;i<n;i++){
		p.push(arr[i]);
	}
	
	int k=3;

	kthmax(p,n,k);

	kthmin(p,n,k);
	


	return 0;
}