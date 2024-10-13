






class Solution {
public:
    vector<int> inOrder(Node* root)
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
                    curr=curr->left;
                }
                //already traversed
                else{
                    
                    rtMost->right=NULL;
                    ans.push_back(curr->data);
                    //left subtreee is traversed already so move right 
                    curr=curr->right;
                    
                    
                }
            }
        }
        
        return ans;
    }
};




/////////////////////////////////////



// #include <iostream>
// using namespace std;

// // Node structure for the binary tree
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
    
//     // Constructor to initialize the node
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// void morrisInorderTraversal(Node* root) {
//     Node* current = root;
    
//     while (current != nullptr) {
//         if (current->left == nullptr) {
//             // No left child, print and move to the right child
//             cout << current->data << " ";
//             current = current->right;
//         } else {
//             // Find the in-order predecessor (rightmost node in the left subtree)
//             Node* predecessor = current->left;
//             while (predecessor->right != nullptr && predecessor->right != current) {
//                 predecessor = predecessor->right;
//             }

//             // Establish a temporary link to the current node
//             if (predecessor->right == nullptr) {
//                 predecessor->right = current;
//                 current = current->left;
//             }
//             // If the temporary link is already established, break it and process the node
//             else {
//                 predecessor->right = nullptr;
//                 cout << current->data << " ";
//                 current = current->right;
//             }
//         }
//     }
// }

// int main() {
//     // Creating a sample binary tree
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);

//     cout << "Morris Inorder Traversal: ";
//     morrisInorderTraversal(root);  // Output will be: 4 2 5 1 3
//     cout << endl;

//     return 0;
// }
