//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int V=adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, 1e9), parent(V);
        
        // Initialize source
        dis[src] = 0;
        pq.push({0, src});
        
        // Dijkstra's algorithm
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int dist = it.first;
            
            for (auto i : adj[node]) {
                int adjNode = i.first;
                int wt = i.second;
                
                if (dist + wt < dis[adjNode]) {
                    dis[adjNode] = dist + wt;
                    pq.push({dis[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends