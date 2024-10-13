// #include<bits/stdc++.h>
// using namespace std;

// void permute( vector<int> &arr, vector<vector<int > >&ans, int index){
// 	//base case
// 	if(index==arr.size()){
// 		ans.push_back(arr);
// 		return;
// 	}
	
//     vector<bool>use(21,0);
	
// 	for(int i=index; i<arr.size();i++){
//         if(use[arr[i]+10]==0){
//         swap(arr[index],arr[i]);
// 		permute(arr,ans,index+1);
// 		swap(arr[index],arr[i]);

//         use[arr[i]+10]=1;
//         }

        

// 	}
// }

// int main(){
// 	vector<vector<int > >ans;
	
// 	vector<int>arr={1,1,3,3};
	
// 	permute(arr,ans,0);
	
// 	for(int i=0; i<ans.size();i++){
// 		for(int j=0;j<ans[0].size(); j++){
			
// 			if(j==0) cout<<"{ ";
// 			cout<<ans[i][j]<<" ";
// 			if(j+1==ans[0].size()) cout<<"}";
			
			
			
// 		}
// 		cout<<endl;
// 	}
	
// 	return 0;
// }


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void permuteRep(vector<int>&arr,int index, int n,vector<vector<int >>&ans){
	
	//base case
	if(index==n){
		ans.push_back(arr);
		return;
	}
	
	
	vector<int>use(21,0);
	for(int i=index; i<n;i++){
		if(use[arr[i]+10]==0){
			swap(arr[index],arr[i]);
			permuteRep(arr,index+1,n,ans);
			swap(arr[index],arr[i]);
			
			use[arr[i]+10]=1;
			
		}
	}
}


int main( ){
	vector<int> arr={2,2,1};
	vector<vector<int> > ans;
	int n=arr.size();
	
	permuteRep(arr,0,n,ans);
	
	for(int i=0; i<ans.size();i++){
		for(int j=0; j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		
		cout<<endl;
	}
	
	
	return 0;
}



























