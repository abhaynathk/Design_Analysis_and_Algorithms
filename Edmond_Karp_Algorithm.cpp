#include <iostream>
#include <limits.h>
#include <string>
#include <queue>
#include <vector>

using namespace std;

#define V 100 // Maximum number of vertices

// Function to perform BFS and find the augmenting path
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V] = {false}; // Mark all vertices as not visited
    queue<int> q; // Queue for BFS

    // Start from the source
    q.push(s);
    visited[s] = true;
    parent[s] = -1; // Source has no parent

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            // If not yet visited and there's a capacity left
            if (!visited[v] && rGraph[u][v] > 0) {
                // If we reached the sink, set parent and return true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
     return false; // No path found
}

// Edmonds-Karp algorithm to find maximum flow
int edmondsKarp(int graph[V][V], int s, int t) {
    int rGraph[V][V]; // Residual graph
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v]; // Initialize residual graph
        }
    }

    int parent[V]; // Array to store the path
    int maxFlow = 0; // There is no flow initially

    // While there's an augmenting path from source to sink
    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = INT_MAX;

        // Find the maximum flow through the path found
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow; // Forward edge
            rGraph[v][u] += pathFlow; // Reverse edge
        }

        maxFlow += pathFlow; // Add path flow to overall flow
    }
    return maxFlow;
}

int main() {
    int graph[V][V] = {0}; // Initialize the graph
    int n, e; // Number of vertices and edges
    cout << "24MAI0114   ABHAYNATH K\n";
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter the edges in the format: (source destination capacity):\n";
    for (int i = 0; i < e; i++) {
    int u, v, capacity;
    cin >> u >> v >> capacity;
    graph[u][v] = capacity; // Add capacity to the graph
}
   int s, t; // Source and sink
   cout << "Enter the source vertex: ";
   cin >> s;
   cout << "Enter the sink vertex: ";
   cin >> t;
   // Calculate and print the maximum flow
   int maxFlow = edmondsKarp(graph, s, t);
   cout << "The maximum possible flow is " << maxFlow << endl;
   return 0;
}
