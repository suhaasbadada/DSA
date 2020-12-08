/*
Increment mixed string is an operation which operates on two strings S1 and S2 of same length to generate a new string S3. The letters in odd position of S3 is one more than the corressponding letter in S1 and the letters in even position of S3 is one more than the corressponding letter in S2. For example, if S1 = ‘amey’ and S2 = ‘dhft’ then S3 = ‘bifu’. For letter ‘z’, letter ‘a’ is one more than it.

 

Fibanocci increment mixed string is operation which operates on the last two strings in the series. Given two strings, S1 and S2 write a code to generate the nth element using Fibanocci increment mixed string operation. The given strings S1 and S2 are the first two elements in the Fibanocci increment mixed string series. Third element in the series is found by applying increment mixed string operation for first two elements.

 

If S1 = ‘amey’ and S2 = ‘dhft’ then the first five elements in the series are as follows:

amey

dhft

bifu

ejgv

ckgw



*/
#include <iostream>
#include <vector>
using namespace std;

string nextString(string s1,string s2){
    string s3;
    int i,j;
    //odd of s1
    for(i=0;i<s1.length();i++){
        if(i%2!=0){
            s3+='$';
        }
        else{
            int ascii=(int)s1[i];
            ascii+=1;
            
            if(ascii>122){
                ascii=97;
            }
            s3+=(char)ascii;
        }
        
    }
    
    //even of s2
    for(j=1;j<s2.length();j+=2){
        int ascii=(int)s2[j];
        ascii+=1;
            
        if(ascii>122){
            ascii=97;
        }
        
        s3[j]=(char)ascii;
    }
    
    return s3;
}



int main(){
    string s1,s2;
    
    cin>>s1>>s2;
    
    int i=0,n;
    cin>>n;
    
    vector <string> v;
    
    v.push_back(s1);
    v.push_back(s2);
    
    for(i=1;i<n-1;i++){
        v.push_back(nextString(v[i-1],v[i]));
    }
    
    cout<<v[v.size()-1];
    
    return 0;
}