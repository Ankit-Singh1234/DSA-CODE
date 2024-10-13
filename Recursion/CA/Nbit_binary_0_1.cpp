#include<bits/stdc++.h>
using namespace std;

void BitNumbers(int n, int one , int zero, string &temp, vector<string>&ans){
	
	//base case 
	if(one+zero==n){
		ans.push_back(temp);
		return ;
	}
	
	//we need in decresing order first we add i and then add for 0;
	
	//we have no conditions for 1
	
	temp.push_back('1');
	BitNumbers(n,one+1,zero,temp,ans);
	temp.pop_back();
	
	
	//adding the '0'
	//we have condition that the number of 1 must be greater than and equal to the number of  Zeros
	
	// for this when the   ( zero < one )  than we can only add zero
	if(zero<one){
		temp.push_back('0');
		BitNumbers(n,one,zero+1,temp,ans);
		temp.pop_back();

	}
	
}


int main (){
	int n=4;
	vector<string>ans;
	string temp;
	int one=0; // no of one
	int zero=0; //number of zeros initilly
	
	BitNumbers(n,one,zero,temp,ans);
	
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
