void totPath(vector<vector<int>>&matrix, int n,int i, int j,string &path, vector<vector<bool>>visited,vector<string>&ans){

	// base case
	if(i==n-1 && j==n-1){
		ans.push_back(path);
		return ;
	}
	
	
	if(matrix[i][j]==1){
		
		visited[i][j]=1;
		
		int row[]={-1,1,0,0};
		int col[]={0,0,-1,1};
		string dir="UDLR";
		
		for(int k=0; k<4; k++){
			if(valid(i+row[k],i+col[k],n) && matrix[i+row[k]][j+col[k]]  && visited[i+row[k]][j+col[k]]){
				
				path.push_back(dir[k]);
				totPath(matrix,n,i+row[k],j+col[k],path,visited,ans);
				path.pop_back();
			}
		}
	}
	
	//mark it unvisited
	visited[i][j]=0;
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