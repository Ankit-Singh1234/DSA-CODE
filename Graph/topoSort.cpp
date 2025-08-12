#include <bits/stdc++.h>
using namespace std;

// DFS function to visit nodes and push them to stack in topological order
void dfs(int node, vector<int> adj[], vector<int>& visited, stack<int>& st) {
    visited[node] = 1;  // Mark current node as visited

    // Visit all neighbors of current node
    for (auto neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited, st);
        }
    }

    // After visiting all neighbors (i.e., dependencies), push current node to stack
    // This ensures dependencies come before current node in topological order
    st.push(node);
}

vector<int> topoSortDFS(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);  // Track visited nodes
    stack<int> st;               // Stack to store topological order

    // Call DFS for every unvisited node
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topoOrder;
    // Pop elements from stack to get topological ordering
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }
    return topoOrder;
}

int main() {
    int V = 6;
    vector<int> adj[V];

    // Build the graph (directed edges)
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Get topological order
    vector<int> ans = topoSortDFS(V, adj);

    // Print the order
    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}

//////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& visited, stack<int>& st) {
    visited[node] = 1;
    for (auto neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topoSortDFS(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> topoOrder;
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }
    return topoOrder;
}

int main() {
    int V = 6;
    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> ans = topoSortDFS(V, adj);
    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}
