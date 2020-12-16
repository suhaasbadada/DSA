#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
In the stock market of the city Knowhere, the stock prices of a given day is calculated as 3 times the price of previous day plus
4 times the price of the day before yesterday.
Given the prices on day 1 and day 2, answer Q queries asking you about the price of the stock on the Nth day.

Print one line containing Q space-separated integer, ith of them denoting the value of the stock price on ith day.
Since there is a possibility of overflow of values while calculating price on ith day (i.e.) values may become larger than the 
value contained in 32 bit integer, so take modulo (10^9+7) wherever required.

Input
4 5
4
1 2 3 998
Expected output
4 5 31 83571769

*/

int main(){
    long long int i,day1,day2;
    cin>>day1>>day2;
    long long int queries;
    cin>>queries;
    vector <long long int> vdays;
    vdays.push_back(day1);
    vdays.push_back(day2);
    vector <long long int> vqueries;
    for(i=0;i<queries;i++){
        long long int dayqueries;
        cin>>dayqueries;
        vqueries.push_back(dayqueries);
    }
    const unsigned int mod=pow(10,9)+7;
    long long int max=vqueries[vqueries.size()-1];
    
    long long int counter=0;
    while(counter!=max){
        long long int a=(3*vdays[counter+1]);
        long long int b=(4*vdays[counter]);
        vdays.push_back((a+b)%mod);
        
        counter++;
    }
    
    for(i=0;i<vqueries.size();i++){
        
        long long int k=(vdays[vqueries[i]-1]);
        
        cout<<k<<" ";
    }
    
    return 0;
}

