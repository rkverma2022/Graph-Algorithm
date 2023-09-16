// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n, m;
    cout<<"Number of nodes = ";
    cin>>n;
    cout<<"Number of Edges = ";
    cin>>m;
    
    int adj_matrix[n + 1][n + 1];
     for(int i = 0; i< n +1; i++)
    {
        for(int j = 0; j < n + 1; j++){
            adj_matrix[i][j] = 0;
        }
        cout<<endl;
    }
    for(int i = 0; i<m; i++)
    {
        int u, v;
        cout<<"enter the edge = ";
        cin>>u>>v;
        
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    for(int i = 1; i< n +1; i++)
    {
        for(int j = 1; j < n + 1; j++){
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
