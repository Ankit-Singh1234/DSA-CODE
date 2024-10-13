#include<bits/stdc++.h>
using namespace std;

void permute(string &str, vector<string>&ans, int index ){
	
	//base case
	if(index==str.length()){
		ans.push_back(str);
		return ;
	}
	
	for(int i=index; i<str.length();i++){
		
		swap(str[index],str[i]);
		permute(str,ans,index+1);
		swap(str[index],str[i]);
	}
}


int main(){
	string str="123";
	vector<string>ans;
	
	permute(str,ans,0);
	
	for(int i=0; i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}
