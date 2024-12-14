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
        int V=adj.size();
        // The pair now stores {vertex, distance}, and the queue is a min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dis(V, 1e9);

        vector<int> parent(V);

        // Initialize the source vertex
        dis[src] = 0; 
        pq.push({src, 0}); // Push the source with node first and distance second

        // Dijkstra's algorithm loop
        while (!pq.empty()) {
            auto it = pq.top(); 
            pq.pop();

            int node = it.first;  // Current node being processed
            int dist = it.second; // Current shortest distance to this node

            // Traverse all adjacent nodes of the current node
            for (auto i : adj[node]) {
                int adjNode = i.first;  // Adjacent node
                int wt = i.second;      // Weight of the edge to the adjacent node

                // Relaxation step
                if (dist + wt < dis[adjNode]) {
                    dis[adjNode] = dist + wt;       // Update the shortest distance
                    pq.push({adjNode, dis[adjNode]}); // Push the updated node into the priority queue
                    parent[adjNode] = node;         // Update the parent for path reconstruction
                }
            }
        }

        // Return the distances from the source to all vertices
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
