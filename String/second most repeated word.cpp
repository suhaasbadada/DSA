#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;


string secondMostRepeated(vector <string> sequence){

	unordered_map <string,int> frequency;

	int i;
	for(i=0;i<sequence.size();i++){
		frequency[sequence[i]]++;
	}

	int first_max=INT_MIN;
	int second_max=INT_MIN;

	for(auto i:frequency){

		if(i.second>first_max){
			second_max=first_max;
			first_max=i.second;
		}

		else if(i.second>second_max && i.second!=first_max){
			second_max=i.second;
		}
	}

	for(auto i:frequency)
		if(i.second==second_max)
			return i.first;

	return "nil";
}

int main(){

	vector<string> seq = { "ccc", "aaa", "ccc","ddd", "aaa", "aaa" }; 



	cout<<secondMostRepeated(seq);



	return 0;
}