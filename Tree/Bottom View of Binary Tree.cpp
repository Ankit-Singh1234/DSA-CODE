
class Solution {
  public:
  
  
  
  
     vector<int> topView(Node *root)
    {
        //Your code here
        
        map<int, int>mpp; // map : store the elent in sorted order
        
        // queue<Node*, int>q;  it is wrong
        
        queue<pair<Node*, int>>q;
        
        
        
        
        q.push({root,0});
        
        while(!q.empty()){       //BFS (level trversal ) aur jab level ka pehla element mile push in map
            
            Node* temp=q.front().first;
            int hd=q.front().second; // horizontal direction
            
            q.pop();
            
           // if(mpp.find(level)==mpp.end()){
                mpp[hd]=temp->data;  // same as the top view , but allow the element to overwrite the the level:value
            //}
            
            if(temp->left){
                q.push({temp->left, hd-1});
            }
             if(temp->right){
                q.push({temp->right, hd+1});
            }
        }
        vector<int> ans;
        for(auto it : mpp){
            
            ans.push_back(it.second);
            
        }
        
        
        return ans;
        
    }
    vector <int> bottomView(Node *root) {
        
        return topView(root);
        // Your Code Here
    }
};
