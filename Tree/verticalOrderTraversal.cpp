#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalOrderTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> verticalMap;
        queue<pair<TreeNode*, pair<int, int>>> nodeQueue;

        nodeQueue.push({root, {0, 0}});
        
        while (!nodeQueue.empty()) {
            auto current = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* node = current.first;
            int vertical = current.second.first;
            int level = current.second.second;
            
            verticalMap[vertical][level].insert(node->value);  
            
            if (node->left) {
                nodeQueue.push({node->left, {vertical - 1, level + 1}});
            }
            if (node->right) {
                nodeQueue.push({node->right, {vertical + 1, level + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& vertical : verticalMap) {
            vector<int> column;
            for (auto& level : vertical.second) {
                column.insert(column.end(), level.second.begin(), level.second.end());
            }
            result.push_back(column);
        }
        return result;
    }
};

void displayVerticalOrder(const vector<vector<int>>& traversal) {
    for (const auto& column : traversal) {
        for (int nodeValue : column) {
            cout << nodeValue << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution solution;
    vector<vector<int>> verticalTraversal = solution.verticalOrderTraversal(root);

    cout << "Vertical Traversal: ";
    displayVerticalOrder(verticalTraversal);

    return 0;
}
