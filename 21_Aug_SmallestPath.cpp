//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> visited(N,0); // Begin by keeping track of all visited Nodes.
        vector<vector<int>> adj(N); // Convert to adjoint matrix
        for(int i = 0; i<M; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]); // Do not forget to add this for undirected Graph
        }
        
        vector<int> dis(N,0); // Calculate Distance
        queue<int> q;
        q.push(src); // BFS queue
        visited[src]=1;
        while(!q.empty()) {
            int xx = q.front();q.pop();
            for(auto x: adj[xx]){
                if(visited[x]==0) {
                    visited[x] = 1;
                    dis[x] = dis[xx]+1;
                    q.push(x);
                }
            }
        }

        // Replace -1 if not reachable
        for(int i = 0; i<N; i++) {
            if(dis[i]==0 && src!=i)
                dis[i] = -1;
        }
        
        return dis;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends