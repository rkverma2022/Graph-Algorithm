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
    
    vector<int> adj_list[n + 1];
    for(int i = 1; i<m+1; i++)
    {
        int u, v;
        cout<<"Enter the edge = ";
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    for(int i =1; i<n+1; i++)
    {
        cout<<i<<" : ";
        for(int node : adj_list[i])
            cout<<node<<" ";
        cout<<endl;
    }
    return 0;
}
