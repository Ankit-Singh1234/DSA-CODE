class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        //code here
         vector<int>ans;
        Node* curr=root;
        
        while(curr!=NULL){
            
            //left part not exist
            if(curr->left==NULL){
                
                ans.push_back(curr->data);
                //move to right
                curr=curr->right;
                
                
            }
            //left part exist
            else{
                
                //goto the rightMost of the left subtree
                Node* rtMost=curr->left;
                while( rtMost->right!=NULL && rtMost->right!=curr){
                    rtMost=rtMost->right;
                }
                
                // I am at rightMost 
                
                //two cases 1.not traverse
                if(rtMost->right==NULL){
                    rtMost->right=curr;
                    ans.push_back(curr->data);// leftpart bhi hand not traversed hai in preorder
                    curr=curr->left;
                }
                //already traversed
                else{
                    
                    rtMost->right=NULL;
                    
                    //left subtreee is traversed already so move right 
                    curr=curr->right;
                    
                    
                }
            }
        }
        
        return ans;
    }
};    