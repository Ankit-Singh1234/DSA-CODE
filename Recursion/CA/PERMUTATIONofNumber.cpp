#include<bits/stdc++.h>
using namespace std;

void permute( vector<int> &arr, vector<vector<int > >&ans, int index){
	//base case
	if(index==arr.size()){
		ans.push_back(arr);
		return;
	}
	
	
	for(int i=index; i<arr.size();i++){
		swap(arr[index],arr[i]);
		permute(arr,ans,index+1);
		swap(arr[index],arr[i]);
	}
}

int main(){
	vector<vector<int > >ans;
	
	vector<int>arr={1,2,3};
	
	permute(arr,ans,0);
	
	for(int i=0; i<ans.size();i++){
		for(int j=0;j<ans[0].size(); j++){
			
			if(j==0) cout<<"{ ";
			cout<<ans[i][j]<<" ";
			if(j+1==ans[0].size()) cout<<"}";
			
			
			
		}
		cout<<endl;
	}
	
	return 0;
}
