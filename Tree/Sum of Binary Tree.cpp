long int sumBT(Node* root)
{
    // Code here
    
    if(root==NULL){
        return 0;
        
    }
    
    return (long int)( root->key+ sumBT(root->left)+sumBT(root->right) );
}