#include <iostream>
#include <vector>
using namespace std;
/*
Kartik has been given many words to type. For each word he types he consumes some time depending on the character that is going to be pressed.
For simplicity, we are going to assume that all the words he has to type consist of only 4 letters 'd' , 'f', 'j' and 'k'.
He can type 'd' and 'f' with the left hand and the letters 'j' and 'k' using the right hand.
When typing a word he takes, he takes 2 seconds to type the first character, for each of the other character he types, 
he takes 2 seconds to type if the character uses other hand and 4 seconds if the character uses the same hand.
If he has typed a word already then he can type that word in half the time taken to type it for the first time.
Given some words, calculate the total time taken to type all the given words.

Input:
4
dfjk
ddd
jkd
dfjk

Output: 
36
*/

bool handChange(char c1,char c2){
    return (((c1=='d'||c1=='f')&&(c2=='j'||c2=='k'))||((c1=='j'||c1=='k')&&(c2=='d'||c2=='f')));

}


int timePerString(string s){
    int i,t=2;
   
    for(i=1;i<s.length();i++){
        if(handChange(s[i-1],s[i])){
            t+=2;
        }else{
            t+=4;
        }
    }
    
   return t;
}

int getCount(vector <string> v,string s){
    int i,count=0;
    
    for(i=0;i<v.size();i++){
        if(v[i]==s){
            count++;
        }
    }
    return count;
}


int main(){
    
    // left -  d,f
    // right - j,k
    // first 2 sec
    // hand change 2 sec
    // same hand 4 sec
    
    int n;
    cin>>n;
    
    vector <string> v;
    int i;
    for(i=0;i<n;i++){
        string type;
        cin>>type;
        v.push_back(type);
    }
    
    int x=0,t,count;
    int total=0;
    int final;
    for(i=0;i<v.size();i++){
        t=timePerString(v[i]);
        count=getCount(v,v[i]);
        
       if(count==1){
           total+=t;
       }
       else{
           x=((t+(t/2)*(count-1)));
       }
        
        final=total+x;        
    } 
    
    cout<<final;

    // can store counts under hashmap for better efficiency
  
    
    
    
    
    return 0;
}