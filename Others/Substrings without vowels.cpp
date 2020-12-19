#include <iostream>
#include <string.h> 
using namespace std;

bool noVowels(string s){
    int i;
    bool f=true;
    for(i=0;i<s.length();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            f=false;
            break;
        }
    }
    return f;
}


int main(){
    string s;
    cin>>s;
    int i,n;
    cin>>n;
    
    for(i=0;i<s.length()-n+1;i++){
        string z=s.substr(i,n);
        if(noVowels(z)){
            cout<<z<<"\n";
        }
    }
    return 0;
}