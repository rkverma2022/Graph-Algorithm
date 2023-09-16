//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited_node(V + 1, 0);
        queue<int> q;
        
        visited_node[0] = 1;
        q.push(0);
        
        vector<int> bfs;
        bfs.push_back(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto adjnode : adj[node]) {
                
                if (!visited_node[adjnode]) {
                    
                    visited_node[adjnode] = 1;
                    
                    q.push(adjnode);
                    
                    bfs.push_back(adjnode);
                }
            }
        }
        
        return bfs;
    

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
