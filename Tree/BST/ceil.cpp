




int findCeil(Node* root, int input) {
    
    int cl=-1;
    if (root == NULL) return cl;
    
    
    while(root!=NULL){
        
        if(root->data==input){
            return root->data;
        }
        
        else if( root->data<input){
            root=root->right;
        }
        else{
            
            cl=root->data;
            root=root->left;
        
        }
        
        
    }
    
    return cl;
    

    // Your code here
}