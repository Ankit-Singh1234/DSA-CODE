
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

      

        //itereative

        stack<TreeNode*>st;
        vector<int>post;

          if(root==NULL){
            return post;
            
        }

        st.push(root);
        while(!st.empty()){

            TreeNode* temp=st.top();
            post.push_back(temp->val);

            st.pop();

             if(temp->left) st.push(temp->left);

            if(temp->right) st.push(temp->right);
           
        }

        reverse(post.begin(), post.end());
        return post;
        
    }
};