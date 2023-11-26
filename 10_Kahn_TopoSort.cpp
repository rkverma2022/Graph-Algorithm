//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void TopologicalSort_DFS(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                TopologicalSort_DFS(it, vis, adj, st);
                
            }
        }
        
        st.push(node);
    }
    
    /*
     kahn toposort
     step 1. find the indegree of each vertex put in a list
     step 2. put the nodes into a queue whose indegree = 0
     step 3. do bfs untill the queue get empty
        step 3.1 take the front node from queue and push into ans
            step 3.1.1 go through all the child of node and decrease their indegree
                step 3.1.1.1 push the child node into queue when indegree = 0
                
    */
    void Kahn_algo_topoSort_BFS(int V, vector<int> adj[], vector<int> &topo) {
        vector<int> Indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                Indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (Indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);
            for (auto it : adj[node]) {
                Indegree[it]--;
                if (Indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector <int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    
	    vector<int> vis(V, 0);
	    vector<int> topo;
	    for(int i = 0; i<V; i++)
	    {
	        if(!vis[i])
	        {
	           // TopologicalSort_DFS(i, vis, adj, st);
	           Kahn_algo_topoSort_BFS(V, adj, topo);
	        }
	    }
	    
	   // vector <int> ans;
	
    // 	while(!st.empty())
    // 	{
    // 	    ans.push_back(st.top());
    // 	    st.pop();
    // 	}
    	
    // 	return ans;
    return topo;
	}
	
	
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
