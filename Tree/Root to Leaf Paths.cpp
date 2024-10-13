
class Solution {
  public:
  
  
    void findAllPath(Node* root, vector<int>&path, vector<vector<int>>&ans){
        
        if(root==NULL){
            return ;
            
        }
        
        path.push_back(root->data);
        
        if(root->left==NULL && root->right==NULL){
            // i am at the route
            // push the arr of all path
            ans.push_back(path);
        }
        else{ // not ath the leaf node so do the recursive call
            
            findAllPath(root->left, path, ans);
            findAllPath(root->right, path, ans);
            
        }
        
        
        path.pop_back();
        
    }
  
  
  
    vector<vector<int>> Paths(Node* root) {
        
        vector<vector<int>>ans;
        vector<int>path;
        
        findAllPath(root, path, ans);
        
        return ans;
        // code here
    }
};