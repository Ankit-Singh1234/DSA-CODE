#include<bits/stdc++.h>
#include<stack>
using namespace std;

// bool isValid( string str){
	
// 	stack<char> st;
// 	for( int i=0; i<str.size(); i++){
		
// 		if(str[i]=='('){
// 			st.push(str[i]);
// 		}
// 		else{
// 			if(st.empty()){
// 				return false;
// 			}
// 			else{
// 				st.pop();
// 			}
// 		}
		
		
		
// 	}
// 	return st.empty();
// }

//using the left variable /////// APProach 2/////

bool isValid(string str){
	int left=0;
	for(int i=0; i<str.size(); i++){

		if(str[i]=='('){
			left++;
		}
		else{
			left--;
		}
	}

	return left==0;
}

int main(){
	
	string str="((((()))))";
	
	cout<<isValid(str)<<endl;
	
	return 0;
	
	
	
	
	
}










