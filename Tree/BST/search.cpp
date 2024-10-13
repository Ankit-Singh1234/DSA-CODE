bool search(Node* root, int x) {
    // Your code here
    
    Node* temp=root;
    if(root==NULL){
        return 0;
    }
    while(temp!=NULL){
        
        if(x==temp->data){
            return 1;
        }
        
        else if(x<=temp->data){
            temp=temp->left;
        }
        
        else{
            temp=temp->right;
        }
        
    }
    
    return 0;
}
