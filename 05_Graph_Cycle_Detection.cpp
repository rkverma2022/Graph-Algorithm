//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
//    USING BFS
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNodes: adj[node])
            {
                if(!vis[adjNodes])
                {
                    vis[adjNodes] = 1;
                    q.push({adjNodes, node});
                }
                else if(parent != adjNodes)
                {
                    return true;
                }
            }
        }
        
        return false;
    }

// USING DFS
    bool detect_cycle_DFS(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(detect_cycle_DFS(it, node, vis, adj))
                    return true;
            }
            else if (it != parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        bool f = false;
        for(int i = 0; i<V; i++)
        {
            if(!vis[i])
            {
                // f = detect(i, adj, vis);
                f = detect_cycle_DFS(i, -1, vis, adj);
                
                if(f)
                    return f;
            }
        }
        return f;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
