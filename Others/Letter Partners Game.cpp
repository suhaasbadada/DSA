/*
In a fun game, every letter in English alphabet has a partner. The first thirteen letters of the English alphabet are called pre-partners and the next thirteen letters are called post-partners. That is ‘a’ is the pre-partner and the corressponding post-partner is ‘n’, ‘b’ is the pre-partner and the corressponding post partner is ‘o’ ....‘m’ is the pre-partner and ‘z’ is the post-partner.

In this game, players will be asked to take a lot with a string ‘w’ and they are said to won the game if the following conditions are satisfied by the letters in ‘w’:

(i) The string may be mixed with pre-partners and post-partners but all pre-partners should have a post-partner

(ii) A pre-partner should come before it’s corressponding post-partner

(iii) For a pre-partner that is in position ‘i’ it’s post-partner

(a) Shall come immediately at posititon ‘i+1’

aerfsbon -> Won
abno -> Lost
abon -> Won
*/
#include <iostream>
#include <vector>
using namespace std;

int ascii(char c){
    return c;
}

int isPreOrPost(char c){
    
    if(ascii(c)>=110){
        return 1;
    }
    else{
        return 0;
    }
}

char correspondingPost(char c){
    return char(ascii(c)+13);
}

bool isPair(int i,int j){
    if(i+1==j){
        return 1;
    }
    return 0;
    
}

int main(){
    
    string s="abno";
   
    vector <int> v1;
    vector <int> v2;
    int i,preInd;
    
    for(i=0;i<s.length();i++){
        if(isPreOrPost(s[i])==0){
           preInd=i;
           int j=preInd;
           while(j<s.length()){
               if(correspondingPost(s[preInd])==s[j]){
                   v1.push_back(preInd);
                   v2.push_back(j);
               }
               j++;
           }
        }
    }
    
    int j;
    int f1=(v1.size()*2==s.length());
    int f2=1;
    for(i=0;i<v1.size();i++){
        for(j=i+1;j<v1.size();j++){
            if(v2[i]<v2[j]){
                f2=0;
            }
        }
        if(f2==0){
            if(isPair(v1[i],v2[i])){
                f2=1;
            }
        }
    }
    
    if(f1==1 && f2==1){
        cout<<"Won"<<"\n";
    }else{
        cout<<"Lost"<<"\n";
    }
  
  	moves(v,n,i_x,i_y,f_x,f_y)?(cout<<"Win"):(cout<<"Loss");

    return 0;
}