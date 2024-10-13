#include<bits/stdc++.h>
using namespace std;


void paren(int n,int L, int R,vector<string>&ans, string temp){
	
	
	//base case
	if(L+R==2*n){
		ans.push_back(temp);
		return;
	}
	
	//add left parenthesis
	if(L<n){
		temp.push_back('(');
		paren(n,L+1,R,ans,temp);
		temp.pop_back();
	}
	
	//add right parenthesis
	
	if(R<L){
		temp.push_back(')');
		paren(n,L,R+1,ans,temp);
		temp.pop_back();
	
    
	}
}



int main(){
	
	int n=3;
	vector<string> ans;
	string temp;
	
	paren(n,0,0,ans,temp);
	
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
