// #include<bits/stdc++.h>
// using namespace std;

// void subseq( string str, int index, int n, vector<vector<char > >&ans,
//                                                         vector<char >temp){
//     //base Case
//     if(index==n){
//         ans.push_back(temp);
//         return;
//     }
    
//     //not inclided
//     subseq(str,index+1,n,ans,temp);
//     //included
//     temp.push_back(str[index]);
//     subseq(str,index+1,n, ans,temp);
// }


// int main(){
//     string str="ankit";
//     vector<vector<char > >ans;
//     vector<char >temp;
    
//     subseq(str,0,5,ans,temp);
    
//     for( int i=0; i<ans.size(); i++){

//         for(int j=0; j<ans[i].size(); j++){
//             cout<<ans[i][j]<<" ";
//             }
//             cout<<endl;
            
            
        
       
//     }

//     return 0;
    
    
    
    
// }

//***************************************************************************** */


// #include<bits/stdc++.h>
// using namespace std;

// // Function to generate all subsequences
// void subseq(string str, int index, int n, vector<vector<char>>& ans, vector<char> temp) {
//     // Base case: if the current index is equal to the length of the string
//     if (index == n) {
//         ans.push_back(temp);  // Add the current subsequence to the result
//         return;
//     }

//     // Not included (move to the next index without including current character)
//     subseq(str, index + 1, n, ans, temp);

//     // Included (include the current character and move to the next index)
//     temp.push_back(str[index]);
//     subseq(str, index + 1, n, ans, temp);
// }

// int main() {
//     string str = "IAF";
//     vector<vector<char>> ans;
//     vector<char> temp;

//     // Generate subsequences
//     subseq(str, 0, str.length(), ans, temp);

//     // Print all subsequences
//     for (int i = 0; i < ans.size(); i++) {
//         for (int j = 0; j < ans[i].size(); j++) {
//             cout << ans[i][j];
//         }
//         cout << endl;  // Print each subsequence on a new line
//     }

//     return 0;
// }

// *****************************************************************************

///////////////////// BEST ///////////////// 
#include<bits/stdc++.h>
using namespace std;

void subseq(string str, int index, int n, vector<string >&ans, string &temp){
	
	//base case
	if(index==n){
		ans.push_back(temp);
		return;
	}
	
	
	//not included
	subseq(str,index+1,n,ans,temp);
	//include
	temp=temp+str[index];
	subseq(str,index+1,n,ans,temp);
	temp.pop_back();
	
}

int main(){
	string str="ankit";
	vector<string> ans;
	string temp;
	
	subseq(str,0,str.length(),ans,temp);
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}
}
