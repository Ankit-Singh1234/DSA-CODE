/*ooooooooooooooooooooooo  MY CODE ooooooooooooooooo*/

class Solution {
  public:
  
    
    Node* makeParentMap(Node* root, int target, unordered_map<Node*, Node*>&nodeParentMap){
        queue<Node*>q;
        
        q.push(root);
        nodeParentMap[root]=NULL;
        Node* targetNode=NULL;
        
        while(!q.empty()){
            
            Node* front=q.front();
            q.pop();
            
            if(front->data==target){
                targetNode=front;
            }
            
            //pushing the neighbour and mappinfg with parrent
            if(front->left){
                q.push(front->left);
                nodeParentMap[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                nodeParentMap[front->right]=front;
            }
        }
        
        return targetNode;
        
    }
    
    
    int burn(Node* target, unordered_map<Node*, Node*>&nodeParentMap){
        
        unordered_map<Node*, bool>visited;
        queue<Node*>q;
        q.push(target);
        visited[target]=1;
        
        int ans=0;
        while(!q.empty()){
            
            int size=q.size();
            int flag=0;
            for(int i=0; i<size; i++){
                Node* front=q.front();
                q.pop();
                
                
                if(front->left && visited[front->left]!=1){
                    q.push(front->left);
                    visited[front->left]=1;
                    flag=1;
                }
                
                if(front->right && visited[front->right]!=1){
                    q.push(front->right);
                    visited[front->right]=1;
                    flag=1;
                }
                
                if(nodeParentMap[front]!=NULL && visited[nodeParentMap[front]]!=1 ){
                    q.push(nodeParentMap[front]);
                    visited[nodeParentMap[front]]=1;
                    flag=1;
                }
            }
            
            if(flag==1){
                ans++;
            }
        }
        
        return ans;
        
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        //steps 
        //1.make map for mapping the parent of the current node
        //2.burn the tree starting from the targeted node point
        
        unordered_map<Node*, Node*>nodeParentMap;
        Node* targetNode=makeParentMap(root,target,nodeParentMap);
        int timeNeeded=burn(targetNode,nodeParentMap);
        return timeNeeded;
    }
};











////////////////// LOVE BABBAR???????????????
// #include <unordered_map>
// #include <queue>

// class Solution {
// public:
//     Node* createParentMapping(Node* root, int target, unordered_map<Node*, Node*>& nodeToParent) {
//         Node* res = NULL;
//         queue<Node*> q;
//         q.push(root);
//         nodeToParent[root] = NULL;

//         while(!q.empty()) {
//             Node* front = q.front();
//             q.pop();

//             if(front->data == target) {
//                 res = front;
//             }

//             if(front->left) {
//                 nodeToParent[front->left] = front;
//                 q.push(front->left);
//             }

//             if(front->right) {
//                 nodeToParent[front->right] = front;
//                 q.push(front->right);
//             }
//         }
//         return res;
//     }

//     int burnTree(Node* targetNode, unordered_map<Node*, Node*>& nodeToParent) {
//         unordered_map<Node*, bool> visited;
//         queue<Node*> q;
//         q.push(targetNode);
//         visited[targetNode] = true;

//         int ans = 0;

//         while(!q.empty()) {
//             bool flag = false;
//             int size = q.size();
//             // for doing simultaneously burn with multiple nodes

//             //processing neighbours and then increase the time if burning occur
//             // or  burn the neighbouring node for the nodes in q
//             for(int i = 0; i < size; i++) {          // love babbar 20:21 / 28:27
//                 Node* front = q.front();    
//                 q.pop();

//                 // Check the left child
//                 if(front->left && !visited[front->left]) {
//                     flag = true;
//                     q.push(front->left);
//                     visited[front->left] = true;
//                 }

//                 // Check the right child
//                 if(front->right && !visited[front->right]) {
//                     flag = true;
//                     q.push(front->right);
//                     visited[front->right] = true;
//                 }

//                 // Check the parent
//                 if(nodeToParent[front] && !visited[nodeToParent[front]]) {
//                     flag = true;
//                     q.push(nodeToParent[front]);
//                     visited[nodeToParent[front]] = true;
//                 }
//             }
            
//             if(flag) ans++;  // Only increase time if a burn happened
//         }

//         return ans;
//     }

//     int minTime(Node* root, int target) {
//         unordered_map<Node*, Node*> nodeToParent;
//         Node* targetNode = createParentMapping(root, target, nodeToParent);
//         int ans = burnTree(targetNode, nodeToParent);
//         return ans;
//     }
// };
