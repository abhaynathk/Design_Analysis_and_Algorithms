#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define V 100

class PushRelabel {
    int n;
    vector<vector<int>> capacity; // Capacity matrix
    vector<vector<int>> flow; // Flow matrix
    vector<int> excess; // Excess flow for each vertex
    vector<int> height; // Height of each vertex

public:
    PushRelabel(int vertices) : n(vertices) {
        capacity.assign(V, vector<int>(V, 0));
        flow.assign(V, vector<int>(V, 0));
        excess.assign(V, 0);
        height.assign(V, 0);
    }

    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap; // Set the capacity of the edge
    }

    void push(int u, int v) {
        int pushFlow = min(excess[u], capacity[u][v] - flow[u][v]);
        flow[u][v] += pushFlow;
        flow[v][u] -= pushFlow;
        excess[u] -= pushFlow;
        excess[v] += pushFlow;
    }

    void relabel(int u) {
         int minHeight = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (capacity[u][v] - flow[u][v] > 0) { // Residual capacity exists
                minHeight = min(minHeight, height[v]);
            }
        }
        if (minHeight < INT_MAX) {
            height[u] = minHeight + 1; // Set new height
        }
    }

    void initializePreflow(int source) {
        height[source] = n; // Set height of the source to n
        for (int v = 0; v < n; v++) {
            if (capacity[source][v] > 0) {
                flow[source][v] = capacity[source][v]; // Push flow to adjacent vertices
                flow[v][source] = -flow[source][v]; // Reverse flow
                excess[v] += flow[source][v]; // Update excess flow
                excess[source] -= flow[source][v];
            }
        }
    }

    int getMaxFlow(int source, int sink) {
        initializePreflow(source);

        queue<int> activeVertices; // Queue for active vertices
        for (int i = 0; i < n; i++) {
            if (i != source && i != sink && excess[i] > 0) {
                activeVertices.push(i); // Add active vertices to the queue
            }
        }

        while (!activeVertices.empty()) {
            int u = activeVertices.front();
            activeVertices.pop();

            bool pushed = false;
            for (int v = 0; v < n; v++) {
                if (capacity[u][v] - flow[u][v] > 0 && height[u] > height[v]) {
                            push(u, v);
                    pushed = true;

                    if (excess[v] == 0) {
                        activeVertices.push(v); // Add vertex to queue if it becomes active
                    }
                }
            }
            if (!pushed) {
                relabel(u); // Relabel if no push is possible
                activeVertices.push(u); // Re-add vertex to queue
            }
        }

        return excess[sink]; // Maximum flow is the excess at the sink
    }
};

int main() {
    cout << "24MAI0114       ABHAYNATH K\n";

    int n, e; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    PushRelabel pr(n); // Create a PushRelabel object

    cout << "Enter the edges in the format: (source destination capacity):\n";
    for (int i = 0; i < e; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        pr.addEdge(u, v, capacity); // Add edge to the graph
    }

    int s, t; // Source and sink
    cout << "Enter the source vertex: ";
    cin >> s;
    cout << "Enter the sink vertex: ";
    cin >> t;
// Check if source and sink are within valid range
if (s < 0 || s >= n || t < 0 || t >= n) {
cout << "Source or sink vertex is out of bounds." << endl;
return 1;
}
// Calculate and print the maximum flow
int maxFlow = pr.getMaxFlow(s, t);
cout << "The maximum possible flow is " << maxFlow << endl;
return 0;
}
