class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        
        if(node==NULL) return ;
        
        Node* temp=node->left;
        node->left=node->right;
        node->right=temp;
        // code here
        
        //left subtree swap
        mirror(node->left);
        mirror(node->right);
        
    }
};
