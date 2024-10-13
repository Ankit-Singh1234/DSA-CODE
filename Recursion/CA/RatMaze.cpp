#include<bits/stdc++.h>
using namespace std;



// step1: mark the current cell as visited
// step2: find the allowed direction and do recursice call
// step3: backtrack and mark the current cell as unvisited
 

bool valid(int i, int j,int n){
	
	return i>=0 && i<n && j>=0 && j<n;
}

void totPath(vector<vector<int>>&matrix,int n,int i, int j,string path,vector<vector<bool>>&visited,vector<string>&ans){
	
	//base case
	if(i==n-1 && j==n-1){
		ans.push_back(path);
		return ;
	}
	
	//sabse pehle chek kar current wala valid hai ki nahi starting main

	if(matrix[i][j]==1){

		
	// mark the current position as visited
	visited[i][j]=1; // 1: visited 
	
	//now find the allowed direction to move from current position
	int row[4]={-1,1,0,0};
	int col[4]={0,0,-1,1}; 
	//char dir[4]={'U','D','L','R'};
	string dir="UDLR";
	     //   U,D,L,R
	     
	for(int k=0; k<4; k++){
		 
		
		
		if(valid(i+row[k],j+col[k],n) && matrix[i+row[k]][j+col[k]]==1 && !visited[i+row[k]][j+col[k]]){
			//direction decide ho gai
			path.push_back(dir[k]);
			// main chal direction ki oor for further calls
			totPath(matrix,4,i+row[k],j+col[k],path,visited,ans);
			
			// le main wapas aa gaya
			path.pop_back();
		
		}
 
	}   
	


	}



	//mark the current unvisited for the further another path calculation
	
	visited[i][j]=false;
	
	
	  
	
}



int main(){
	
	/*{{1, 0, 0, 0},
{1, 1, 0, 1},
{1, 1, 0, 0},
{0, 1, 1, 1}}

*/
	vector<vector<int>>matrix={{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
	string path;
	vector<string>ans;
	vector<vector<bool>> visited(4,vector<bool>(4,0));
	
	totPath(matrix,4,0,0,path,visited,ans);
	
	
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}



    return 0;



	
}

/******************************* PRACTICE CODE ONCE AGAIN  */








// void totPath(vector<vector<int>>&matrix, int n,int i, int j,string &path, vector<vector<bool>>&visited,vector<string>&ans){

// 	// base case
// 	if(i==n-1 && j==n-1){
// 		ans.push_back(path);
// 		return ;
// 	}
	
	
// 	if(matrix[i][j]==1){
		
// 		visited[i][j]=1;
		
// 		int row[]={-1,1,0,0};
// 		int col[]={0,0,-1,1};
// 		string dir="UDLR";
		
// 		for(int k=0; k<4; k++){
// 			if(valid(i+row[k],j+col[k],n) && matrix[i+row[k]][j+col[k]]  && !visited[i+row[k]][j+col[k]]){
				
// 				path.push_back(dir[k]);
// 				totPath(matrix,n,i+row[k],j+col[k],path,visited,ans);
// 				path.pop_back();
// 			}
// 		}
// 	}
	
// 	//mark it unvisited
// 	visited[i][j]=0;
// }

// int main(){
	
// 	/*{{1, 0, 0, 0},
// {1, 1, 0, 1},
// {1, 1, 0, 0},
// {0, 1, 1, 1}}

// */
// 	vector<vector<int>>matrix={{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
// 	string path;
// 	vector<string>ans;
// 	vector<vector<bool>> visited(4,vector<bool>(4,0));
	
// 	totPath(matrix,4,0,0,path,visited,ans);
	
	
// 	for(int i=0; i<ans.size(); i++){
// 		cout<<ans[i]<<endl;
// 	}



//     return 0;



	
// }
















/********************* INDENTATION  */
/*#include<bits/stdc++.h>
using namespace std;



//step1: mark the current cell as visited
//step2: find the allowed direction and do recursice call
//step3: backtrack and mark the current cell as unvisited
 

bool valid(int i, int j,int n){
	
	// if ( i>=0 && i<n && j>=0 && j<n){
	// 	return true;
	// }
	// else{
	// 	return false;
	// }

	return i>=0 && i<n && j>=0 && j<n;
}

void totPath(vector<vector<int>>&matrix,int n,int i, int j,string path,vector<vector<bool>>&visited,vector<string>&ans){
	
	//base case
	if(i==n-1 && j==n-1){
		ans.push_back(path);
		return ;
	}
	
	//sabse pehle chek kar current wala valid hai ki nahi starting main

	if(matrix[i][j]==1){

		
	// mark the current position as visited
	visited[i][j]=1; // 1: visited 
	
	//now find the allowed direction to move from current position
	int row[4]={-1,1,0,0};
	int col[4]={0,0,-1,1}; 
	//char dir[4]={'U','D','L','R'};
	string dir="UDLR";
	     //   U,D,L,R
	     
	for(int k=0; k<4; k++){
		 
		
		
		if(valid(i+row[k],j+col[k],n) && matrix[i+row[k]][j+col[k]]==1 && !visited[i+row[k]][j+col[k]]){
			//direction decide ho gai
			path.push_back(dir[k]);
			// main chal direction ki oor for further calls
			totPath(matrix,4,i+row[k],j+col[k],path,visited,ans);
			
			// le main wapas aa gaya
			path.pop_back();
		
		}
 
	}   
	


	}



	//mark the current unvisited for the further another path calculation
	
	visited[i][j]=false;
	
	
	  
	
}



int main(){
	

	vector<vector<int>>matrix={{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
	string path;
	vector<string>ans;
	vector<vector<bool>> visited(4,vector<bool>(4,0));
	
	totPath(matrix,4,0,0,path,visited,ans);
	
	
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}



    return 0;



	
}
*/













/****************************   using separate u d,l r  */

/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>>& matrix, vector<vector<bool>>& visited) {
    // Check if the current cell (x, y) is within bounds and not yet visited, and if it's a path (i.e., matrix[x][y] == 1)
    return (x >= 0 && x < n && y >= 0 && y < n && matrix[x][y] == 1 && !visited[x][y]);
}

void findPaths(vector<vector<int>>& matrix, int n, int x, int y, string path, vector<vector<bool>>& visited, vector<string>& ans) {
    // If the destination (n-1, n-1) is reached, add the path to the result
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Move Down (D)
    if (isSafe(x + 1, y, n, matrix, visited)) {
        findPaths(matrix, n, x + 1, y, path + 'D', visited, ans);
    }

    // Move Right (R)
    if (isSafe(x, y + 1, n, matrix, visited)) {
        findPaths(matrix, n, x, y + 1, path + 'R', visited, ans);
    }

    // Move Up (U)
    if (isSafe(x - 1, y, n, matrix, visited)) {
        findPaths(matrix, n, x - 1, y, path + 'U', visited, ans);
    }

    // Move Left (L)
    if (isSafe(x, y - 1, n, matrix, visited)) {
        findPaths(matrix, n, x, y - 1, path + 'L', visited, ans);
    }

    // Backtrack: Unmark the current cell as visited for other possible paths
    visited[x][y] = false;
}

vector<string> findAllPaths(vector<vector<int>>& matrix, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    // If the starting cell is blocked, return an empty result
    if (matrix[0][0] == 0) {
        return ans;
    }
    
    string path;
    findPaths(matrix, n, 0, 0, path, visited, ans);
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1, 0, 0, 0}, 
                                  {1, 1, 0, 1}, 
                                  {1, 1, 0, 0}, 
                                  {0, 1, 1, 1}};
    
    int n = 4;
    vector<string> result = findAllPaths(matrix, n);

    // If there are no valid paths, output -1
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        for (const string& path : result) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}

*/


