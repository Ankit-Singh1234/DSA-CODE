// fnd number of SCC
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs1(neigh, adj, visited, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> transpose[], vector<bool> &visited) {
    visited[node] = true;
    for (int neigh : transpose[node]) {
        if (!visited[neigh]) {
            dfs2(neigh, transpose, visited);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(V, false);

    // Step 1: DFS on original graph
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    // Step 2: Transpose the graph
    vector<int> transpose[V];
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            transpose[v].push_back(u);
        }
    }

    // Step 3: DFS on transpose graph in stack order to count SCCs
    fill(visited.begin(), visited.end(), false);
    int sccCount = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            dfs2(node, transpose, visited);
            sccCount++;  // Ek SCC complete hua, count badhao
        }
    }

    cout << sccCount << "\n";

    return 0;
}
//////////////////////////////////////////////

//All SCC in a 2d vector

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs1(neigh, adj, visited, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> transpose[], vector<bool> &visited, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);
    for (int neigh : transpose[node]) {
        if (!visited[neigh]) {
            dfs2(neigh, transpose, visited, component);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];
    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(V, false);

    // Step 1: DFS on original graph to fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    // Step 2: Transpose the graph
    vector<int> transpose[V];
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            transpose[v].push_back(u);
        }
    }

    // Step 3: DFS on transpose graph to find SCCs
    fill(visited.begin(), visited.end(), false);

    vector<vector<int>> allSCCs;  // 2D vector to store all SCCs

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            vector<int> component;
            dfs2(node, transpose, visited, component);
            allSCCs.push_back(component);  // Store this SCC in allSCCs
        }
    }

    // Print all SCCs
    cout << "Strongly Connected Components (SCCs) are:\n";
    for (const auto &scc : allSCCs) {
        for (int v : scc) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
