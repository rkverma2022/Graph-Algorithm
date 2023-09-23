//{ Driver Code Starts
// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private:
    void nearest_using_bfs(vector<vector<int>>& grid, vector<vector<int>>& ans, vector<vector<int>>& vis)
    {
        queue<pair<pair<int, int>, int>> q;  // q<<row, col>, dis>

        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> neighbour = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
                else
                {
                    ans[i][j] = -1; // Initialize with -1 for cells with 0
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            for (auto it : neighbour)
            {
                int nrow = row + it.first;
                int ncol = col + it.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    int updated_dist = dist + 1;
                    q.push({{nrow, ncol}, updated_dist});

                    ans[nrow][ncol] = updated_dist;
                }
            }
        }
    }
    
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    
	    
	    nearest_using_bfs(grid, ans, vis);
	    
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
