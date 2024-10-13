

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

    int target=9;


	vector<int> ansSum;
	vector<vector<int > >ansSet;
	vector<int> temp;
	
	subsetSum(arr,0,4,ansSet,ansSum,temp,0);

    int found=0;
    for(int i=0; i<ansSum.size(); i++){
        if(ansSum[i]==target){
            found=1;
            for(int j=0;j<ansSet[i].size(); j++){
                if(j==0) cout<<"{ ";
                cout<<ansSet[i][j]<<" ";
                if(j+1==ansSet[i].size()) cout<<"}";
            }
        } 
        
    }
    if(found==0) cout<<"not found"<<endl;

	// for(int i1=0, i2=0; i1<ansSum.size(),i2<ansSet.size(); i1++,i2++){
	// 	for( int j=0; j<ansSet[i2].size();j++){

	// 		if(j==0) cout<<"{ ";
	// 		cout<<ansSet[i2][j]<<" ";
	// 		if(j+1==ansSet[i2].size()) cout<<"}";

	// 	}
		
	// 	cout<<" = "<<ansSum[i1]<<endl;
	// }

	
	return 0;


}
