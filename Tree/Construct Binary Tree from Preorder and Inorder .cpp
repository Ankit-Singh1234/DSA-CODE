/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* Tree(vector<int>&preorder , int preStart, int preEnd,  vector<int>& inorder,int  inStart,int inEnd ,  unordered_map<int,int>& inMap){

        if(preStart>preEnd  || inStart>inEnd){
            return NULL;
        }

        TreeNode* root= new TreeNode(preorder[preStart]);

        int inRoot=inMap[root->val];

        int inLeft=inRoot-inStart;

        root->left=Tree(preorder, preStart+1,preStart+inLeft,   inorder, inStart, inRoot-1,  inMap);
        root->right=Tree(preorder, preStart+inLeft+1, preEnd,    inorder,inRoot+1, inEnd,       inMap);



        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n=inorder.size();

        unordered_map<int , int>inMap;
        for( int i=0; i<n ; i++ ){
            inMap[inorder[i]]=i;

        }

        TreeNode* root=Tree(preorder, 0,n-1,   inorder, 0, n-1,    inMap);

        return root;


        
    }
};