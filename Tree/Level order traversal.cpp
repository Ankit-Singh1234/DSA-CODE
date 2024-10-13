
class Solution
{
    public:
    
    void levOrder(Node* root, vector<int>&ans){
        
        if(root==NULL) return;
        
        queue<Node* > q;
        
        q.push(root);
        
        while(!q.empty()){
            Node* curr=q.front();
            
            q.pop();
            
            ans.push_back(curr->data);
            
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) ans.push_back(curr->right);
        }
    }
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    
    
    {
      //Your code here
      vector<int>ans;
      levOrder(root,ans);
      return ans;
    }
};
