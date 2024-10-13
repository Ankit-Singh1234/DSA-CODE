Node *deleteNode(Node *root, int x) {
    
    
    // your code goes here
    
    if(root==NULL){
        return NULL;
    }
    
    if(x<root->data){
        root->left=deleteNode(root->left,x);
    }
    
    else if(x>root->data){
        root->right=deleteNode(root->right, x);
    }
    else{
        //when the x founded
        
        //Node child
        //1 child ( left or right)
        //2 child
        
        //No child
        
        if(root->left==NULL && root->right==NULL){
            
            delete root;
            return NULL;
            
        }
        
        // else if(root->left!=NULL && root->right==NULL){
        else if(root->right==NULL){     // islke alawa koi b hi condition mahi lagana
            //left child exist
            
            Node* temp=root->left;
            delete root;
            return temp;
            
        }
        // else if(root->right==NULL && root->right!=NULL){
        else if(root->left==NULL){
        
            //left child exist
            
            Node* temp=root->right;
            delete root;
            return temp;
            
        }
        
        else{
            //both child exist
            
            Node * prev=root;
            Node* leftMax=root->left;
            
            while(leftMax->right!=NULL){
                prev=leftMax;
                leftMax=leftMax->right;
            }
            
            
            //when 
            if(prev!=root){
                prev->right=leftMax->right;
                
                leftMax->left=root->left;
                leftMax->right=root->right;
                
                delete root;
                return leftMax;
            }
            
            else{
                leftMax->right=root->right;
                delete root;
                return leftMax;
            }
        }
        
        
        return root;
        
        
    }
}
