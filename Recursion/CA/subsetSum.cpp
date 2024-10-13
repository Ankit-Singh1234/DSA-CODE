// #include<bits/stdc++.h>
// using namespace std;

// void subsetSum( int arr[], int index, int n, int sum){
	
	
// 	//base case
// 	if(index==n){
// 		cout<<sum<<endl;
// 		return ;
// 	}
	
	
	
// 	// NOT taken for some
// 	subsetSum(arr,index+1,n,sum);
// 	// YES Taken for the sum
	
// 	subsetSum(arr,index+1,n,sum+arr[index]);
// }

// int main(){
// 	int arr[]={1,2,3,4};
	
// 	subsetSum(arr,0,4,0);
	
// 	return 0;
// }

///************************************************************************************* */
// #include<bits/stdc++.h>
// using namespace std;

// void subsetSum( int arr[], int index, int n, vector<int>&ans ,int sum){
	
	
// 	//base case
// 	if(index==n){
// 		ans.push_back(sum);
// 		return ;
// 	}
	
	
	
// 	// NOT taken for some
// 	subsetSum(arr,index+1,n,ans,sum);
// 	// YES Taken for the sum
	
// 	subsetSum(arr,index+1,n,ans,sum+arr[index]);
// }

// int main(){
// 	int arr[]={1,2,3,4};
// 	vector<int> ans;
	
// 	subsetSum(arr,0,4,ans,0);

// 	for(int i=0; i<ans.size(); i++){
// 		cout<<ans[i]<<" ";
// 	}
// 	return 0;
// }
///************************************************************************** */




#include<bits/stdc++.h>
using namespace std;

void subsetSum( int arr[], int index, int n,vector<vector<int > >&ansSet, vector<int>&ansSum ,
                                            vector<int> &temp,int sum){
	
	
	//base case
	if(index==n){
		ansSet.push_back(temp);
		ansSum.push_back(sum);
		return ;
	}
	
	
	
	// NOT taken for some
	subsetSum(arr,index+1,n,ansSet,ansSum,temp,sum);
	// YES Taken for the sum
	temp.push_back(arr[index]);
	subsetSum(arr,index+1,n,ansSet,ansSum,temp,sum+arr[index]);
	temp.pop_back();
}

int main(){
	int arr[]={1,2,3,4};
	vector<int> ansSum;
	vector<vector<int > >ansSet;
	vector<int> temp;
	
	subsetSum(arr,0,4,ansSet,ansSum,temp,0);

	for(int i1=0, i2=0; i1<ansSum.size(),i2<ansSet.size(); i1++,i2++){
		for( int j=0; j<ansSet[i2].size();j++){

			if(j==0) cout<<"{ ";
			cout<<ansSet[i2][j]<<" ";
			if(j+1==ansSet[i2].size()) cout<<"}";

		}
		
		cout<<" = "<<ansSum[i1]<<endl;
	}

	
	return 0;


}
