#include <iostream>
#include <cstring>
using namespace std;

void SieveOfEratosthenesSum(int n) 
{ 

    bool primes[n+1]; 
    memset(primes,true, sizeof(primes)); 
    int i,j;
    for (i=2; i*i<=n;i++) 
    { 
        if (primes[i]==true) 
        { 
            for (j=i*i;j<=n;j+=i) 
                primes[j] = false; 
        } 
    } 

    int sum=0;
    for (int p=2; p<=n; p++) 
       if (primes[p]){  
           if(sum<n){
               sum+=p;
           }
       } 
   
      if(sum==n){
          cout<<"Yes";
      }else{
          cout<<"No";
      }
          
} 
  
int main(){
    
    int n;
    n=1060;
   // cin>>n;
    
    SieveOfEratosthenesSum(n);
    
    
    return 0;
}