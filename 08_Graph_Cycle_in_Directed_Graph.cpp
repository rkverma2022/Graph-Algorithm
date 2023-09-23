//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
       bool isCyclic_DFS(int node, vector<int> &vis, vector<int> adj[]) {
            vis[node] = 1; // Mark the node as visiting
    
            for (auto child_node : adj[node]) {
                if (vis[child_node] == 1) {
                    return true; // Found a back edge, so there's a cycle
                } else if (vis[child_node] == 0) {
                    if (isCyclic_DFS(child_node, vis, adj)) {
                        return true; // Recursively check child nodes
                    }
                }
            }
    
            vis[node] = 2; // Mark the node as visited after visiting all its children
            return false;
        }
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> vis(V, 0);
        
       for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (isCyclic_DFS(i, vis, adj)) {
                    return true; // If a cycle is detected, return true
                }
            }
        }

        return false; 
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
