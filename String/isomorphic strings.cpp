#include <iostream>
#include <map>
using namespace std;

bool Isomorphic(string s1,string s2){
    map <char,char> m;

    if(s1.length()!=s2.length()){
        return false;
    }

    int i;
    for(i=0;i<s1.length();i++){
        m[s1[i]]=s2[i];
    }
    
    string z="";
    
    for(i=0;i<s1.length();i++){
        z+=m[s1[i]];
    }

    return z==s2;
}


int main(){
    
    string s1,s2;
    
    cout<<Isomorphic("aab","xxy")<<"\n";
    cout<<Isomorphic("aab","xyz")<<"\n";
    cout<<Isomorphic("aacdef","xxyzqp")<<"\n";
    

    
    return 0;
}