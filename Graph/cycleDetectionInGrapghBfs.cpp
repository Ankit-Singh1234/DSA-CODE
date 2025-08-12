yeh hasCycleBFS() ka aim sirf traversal nahi hai, balki poore graph me kahin bhi cycle hai ya nahi ye detect karna hai.

Isliye:

cpp
Copy
Edit
if (bfsCycleCheck(i, adj, visited))
    return true;
ka matlab hota hai:

BFS chalao is component pe

Agar BFS ne cycle detect ki → kaam khatam, turant true return karo

Agar BFS ne cycle detect nahi ki → loop next unvisited node pe chalao

#include <bits/stdc++.h>
using namespace std;

// BFS se check karega ki current component me cycle hai ya nahi
bool bfsCycleCheck(int start, vector<vector<int>> &adj, vector<int> &visited) {
    queue<pair<int, int>> q; // {node, parent}
    visited[start] = 1;
    q.push({start, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = 1;
                q.push({neigh, node});
            }
            else if (neigh != parent) {
                // Already visited aur parent bhi nahi hai => cycle found
                return true;
            }
        }
    }
    return false;
}

// Poore graph ke liye cycle check karega
bool hasCycleBFS(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (bfsCycleCheck(i, adj, visited))
                return true; // Jaise hi cycle mile turant return
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    if (hasCycleBFS(n, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

// DFS se check karega ki current component me cycle hai ya nahi
bool dfsCycleCheck(int node, int parent, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1;

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            if (dfsCycleCheck(neigh, node, adj, visited))
                return true;
        }
        else if (neigh != parent) {
            // Already visited aur parent bhi nahi hai => cycle found
            return true;
        }
    }
    return false;
}

// Poore graph ke liye cycle check karega
bool hasCycleDFS(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycleCheck(i, -1, adj, visited))
                return true; // Jaise hi cycle mile turant return
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    if (hasCycleDFS(n, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}
