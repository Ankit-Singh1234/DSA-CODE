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


// Step 1: DFS on Original Graph with Finish Time Tracking
// Pehle hum graph par DFS karte hain.

// Jab hum kisi node par DFS kar rahe hote hain, toh jab wo node ka saara connected nodes visit ho jate hain, tab hum us node ko stack mein push kar dete hain.

// Matlab, jitna der hum kisi node ke andar "kaam" karenge, uske baad jab wo complete ho jata hai, tab hum us node ko stack mein daalte hain.

// Isse kya hoga? Jo node sabse aakhri finish hoga, wo sabse upar stack mein rahega.

// Is stack mein nodes finish hone ke order mein hote hain (jo sabse pehle finish hua, wo neeche, jo last finish hua, wo upar).

// Step 2: Transpose Graph (Reverse All Edges)
// Ab hum graph ke saare edges ki direction reverse kar dete hain.

// Jo edge u -> v tha, ab wo v -> u ban jayega.

// Is naye graph ko transpose graph kehte hain.

// Ye step important isliye hai kyunki hum ab dusri baar DFS karenge, lekin reverse direction mein.

// Step 3: DFS on Transpose Graph in Stack Order
// Ab hum stack se nodes ek-ek karke nikalte hain, matlab finish hone ke reverse order mein.

// Har baar jab stack se koi node nikale, agar wo visit nahi hua ho to hum DFS chalayenge transpose graph par us node se.

// Jo bhi nodes DFS mein visit honge wo ek Strongly Connected Component (SCC) banate hain.

// Kyunki hum transpose graph mein reverse direction mein DFS kar rahe hain, to ye connected components accurately milte hain.

// Step 4: Each DFS tree from step 3 is one SCC
// Har DFS call jo hum transpose graph pe karte hain, wo ek alag SCC ko represent karta hai.

// Is tarah hum graph ke saare SCCs find kar lete hain.

// Short Summary in Hinglish
// Pehle graph mein DFS karo aur finish hone wale nodes ko stack mein daalo.

// Graph ke edges reverse karo (transpose).

// Ab stack se nodes nikal ke transpose graph pe DFS chalao.

// Jo bhi nodes ek DFS mein aayen, wo ek SCC hain.

// Agar chaho toh main example bhi samjha sakta hoon ya code ka explanation bhi Hinglish mein de sakta hoon. Kya chahiye?








// You said:
// Step 3 nahi samjh aaya transpose kyun aur stack se  node lane se kya fayeda , dfs1 ka kya use ause jo node stack one mein uska kya use


// ChatGPT said:
// Achha, main Step 3 ko bahut hi simple aur step-by-step tarike se samjhata hoon — bilkul easy Hinglish mein:

// Step 3 samajhne ke liye pehle Step 1 aur 2 ko thoda clear karte hain:
// Step 1 recap:
// Jab hum DFS karte hain original graph pe, toh hum nodes ko finish hone ke time pe stack mein daalte hain.

// Iska matlab: Jo node sabse baad mein pura explore hota hai, wo sabse upar stack mein rahta hai.

// Yeh finish time hume ek order deta hai jisme hum nodes ko next step mein explore karenge.

// Step 2 recap:
// Graph ke saare edges ko ulta kar dete hain (transpose graph).

// Matlab, agar u -> v tha, toh ab v -> u ho jayega.

// Ab Step 3: DFS on Transpose Graph in stack order
// Ab question aata hai:

// Transpose graph kyu?

// Stack se nodes kyu la rahe hain?

// DFS1 ka use kya hai?

// 1. Transpose graph kyu?
// Original graph me agar nodes ka group strongly connected hai, toh unke beech path dono directions me hote hain.

// Lekin agar hum DFS normal order me karenge transpose graph pe bina kisi order ke, toh hume SCC nahi milenge clearly.

// Transpose karne ka fayda: Jo nodes pehle finish hue, unka reverse order me DFS karne se hum "deepest" SCC se start karte hain aur ek SCC ko poora ek saath visit kar lete hain.

// 2. Stack se nodes kyu la rahe hain?
// DFS1 (Step 1) mein humne nodes ko finish hone ke order mein stack mein daala tha.

// Jo node last finish hua, wo stack ke top pe hai.

// Matlab, hum un nodes se start karenge jinke paas sabse "deep" connections hain.

// Is order me DFS karne se hum ek SCC ko poora explore kar paate hain bina kisi interruption ke.

// 3. DFS1 ka use kya hai?
// DFS1 hume finish time order deta hai — matlab hume pata chalta hai kaunse nodes ko baad me visit karna chahiye transpose graph me.

// Agar hum randomly DFS kare transpose graph pe, toh hum sahi SCC nahi milenge.

// DFS1 stack hume ek order deta hai jisme SCC ko accurately detect kar sakte hain.

// Example se samjhate hain:
// Maan lo:

// Node 1 finish hota hai sabse pehle (matlab DFS uske aas paas explore karta hai), toh wo stack ke neeche rahega.

// Node 5 finish hota hai sabse aakhir mein, toh wo stack ke top pe rahega.

// Ab jab hum transpose graph pe DFS karenge, toh hum pehle node 5 se DFS start karenge (stack ke top se), jisse wo apni puri SCC ko ek baar me visit kar lega.
// Phir stack se neeche wale nodes pe jayenge.

// Summary:
// DFS1 se hum finish order ka stack banate hain.

// Transpose graph me DFS iss order me karne se strongly connected components alag se milte hain.

// Stack se nodes laane ka matlab hai hum highest finish time se start karenge, jisse hum ek SCC ko pura cover kar sakte hain.
