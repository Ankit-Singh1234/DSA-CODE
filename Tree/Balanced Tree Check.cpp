class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node* root, int &valid){
        
        if ( root==NULL){
            return 0;
        }
        
        
        int l=height(root->left,valid);
        int r=height(root->right, valid);
        
        //checking the diff
        
        if( abs(l-r)>1){
            valid=0;
        
        }
        
        // return height for taking the value for the next checkUp
        
        return 1+max(l,r);
        
        
        
    }
    
    bool isBalanced(Node *root){
    
        //  Your Code here
        
        int valid=1;
        
        height(root, valid);
        
        return valid;
    }
};