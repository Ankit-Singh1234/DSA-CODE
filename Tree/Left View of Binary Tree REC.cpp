void Rview( Node* root, int level, vector<int>&ans){
    
    if(root==NULL){
        return ;
        
    }
    
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    
    Rview(root->left, level+1, ans);
    Rview(root->right, level+1, ans);
    
    
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int > ans;
   if(root==NULL){
       return ans;
   }
   
   Rview(root, 0, ans);
   return ans;
}