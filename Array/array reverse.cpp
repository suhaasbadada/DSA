#include <iostream>
using namespace std;



int main(){


   int arr[]={32,11,56,23,87,79,23};
   int i;
   int len=sizeof(arr)/sizeof(arr[0]);

   for(i=len-1;i>=0;i--){
   	cout<<arr[i]<<" ";
   }


    return 0;
}