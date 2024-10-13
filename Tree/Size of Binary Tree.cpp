// method 1

class Solution {
  public:
  
    void size( Node* root, int &cnt){
        
        if(root==NULL){
            return ;
        }
        
        cnt++;
        size(root->left,cnt);
        size(root->right, cnt);
    }
    int getSize(Node* node) {
        // code here
        int cnt;
        size(node,cnt);
    return cnt;
    }
};



