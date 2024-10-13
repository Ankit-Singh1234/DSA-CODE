#include<iostream>
using namespace std;

int count(int arr[], int index, int n, int sum){
	
	
	// base case
	if(index==n){
		if(sum==0){
			return 1;
		}
		else{
			return 0;
		}
		
	}
	
	
	return count(arr,index+1,n,sum) + count(arr,index+1,n,sum-arr[index]);
}


int main(){
	//int arr[]={ -1,2,1};
	int arr[]={ 6,4,2,8,3,7,0};
	int sum=10;
	
	cout<<count(arr,0,7,sum)<<endl;
	
	
	
	return 0;
	
}

//a?





