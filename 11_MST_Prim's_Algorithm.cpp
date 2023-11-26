//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	/*
	    Primes Algorithm :: MST
	    step 1: min_heap_queue priority_queue (wt, node, parent), put any vertex with parent -1
	    step 2: run bfs until, take the top of queue and if it isn't vis then vis it and UPDATE the MST sum
	    step 3: loop for the adjnode
	*/
	
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        vector<int> vis(V, 0);
        
        // Min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // {node, weight}
        pq.push({0, 0});
        
        while (!pq.empty())
        {
            auto it = pq.top();
            int node = it.second; // Corrected here
            int weight = it.first; // Corrected here
            
            pq.pop(); // Pop the top element
            
            if (!vis[node])
            {
                vis[node] = 1;
                sum += weight;
                
                for (auto It : adj[node])
                {
                    int adjNode = It[0];
                    int ewt = It[1];
                    
                    if (!vis[adjNode])
                    {
                        pq.push({ewt, adjNode}); // Corrected here
                    }
                }
            } 
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
