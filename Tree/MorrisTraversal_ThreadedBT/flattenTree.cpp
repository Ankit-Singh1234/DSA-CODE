class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        
        
        
        while(root!=NULL){
            
            //left part not exist
            if(root->left==NULL){
                root=root->right;
            }
            else{
                Node* curr=root->left;
                
                while(curr->right!=NULL){
                    curr=curr->right;
                }
                
                curr->right=root->right;
                root->right=root->left;
                root->left=NULL;
                
                root=root->right;
                
                
                
                
            }
        }
        
    }
};