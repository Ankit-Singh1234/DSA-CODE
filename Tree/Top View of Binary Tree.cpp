class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        
        map<int, int>mpp; // map : store the elent in sorted order
        
        // queue<Node*, int>q;  it is wrong
        
        queue<pair<Node*, int>>q;
        
        
        
        
        q.push({root,0});
        
        while(!q.empty()){
            
            Node* temp=q.front().first;
            int hd=q.front().second; // horizontal distance
            
            q.pop();
            
            if(mpp.find(hd)==mpp.end()){
                mpp[hd]=temp->data;
            }
            
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

};
