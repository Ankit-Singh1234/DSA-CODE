
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL) return 1;
        
        if( (r1==NULL && r2!=NULL) || ( r1!=NULL && r2==NULL) ) return 0;
        
        return ( r1->data==r2->data) && ( isIdentical(r1->left, r2->left) ) && 
                                        ( isIdentical(r1->right, r2->right) );
    }
};









// class Solution{
//     public:
//     //Function to find the height of a binary tree.
//     int height(struct Node* node){
        
        
//         if(node==NULL) return 0;
        
        
        
//         return 1 + max(height(node->left), height(node->right));
//         // code here 
//     }
// };