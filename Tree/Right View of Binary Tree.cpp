class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       
       vector<int>ans;
   
   if(root==NULL){
       return ans;
   }
   
   queue<Node*>q;
   
   
   q.push(root);
   
   while(!q.empty()){
       ans.push_back(q.front()->data);
       int n=q.size();
       
       while(n--){
           Node* temp=q.front();
           q.pop();
            if(temp->right){
               q.push(temp->right);
           }
           
           if(temp->left){
               q.push(temp->left);
           }
          
           
       }
   }
   
   return ans;
    }
};