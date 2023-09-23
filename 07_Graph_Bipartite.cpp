//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool isBipartite_BFS(vector<int>&visited_and_colored, vector<int> adj[], int s)
    {
        queue<int>q;
        q.push(s);
        visited_and_colored[s] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto neighbour_node : adj[node])
            {
                if(visited_and_colored[neighbour_node] == -1)
                {
                    visited_and_colored[neighbour_node] = !visited_and_colored[node];
                    q.push(neighbour_node);
                }
                else if(visited_and_colored[node] == visited_and_colored[neighbour_node])
                {
                    return false;   
                }
            }
        }
        
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> visited_and_colored(V, -1);     //-1 : node not visited
	    // color with 0 and 1
	    
	    for(int i = 0; i<V; i++)
	    {
	        if(visited_and_colored[i] == -1)
	        {
	            if(!isBipartite_BFS(visited_and_colored, adj, i))
	                return false;
	            
	        }
	    }
	    
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
