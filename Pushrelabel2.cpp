#include <bits/stdc++.h>
using namespace std;
struct vertex {
int eflow, ht;
};
int v, e;
int **cap, **flow;
struct vertex *vert;
void preflow(int s) {
vert[s].ht = v;
for (int i = 0; i < v; i++) {
if (i != s && cap[s][i] != 0) {
flow[s][i] += cap[s][i];
flow[i][s] -= cap[s][i];
vert[i].eflow += cap[s][i];
}
 }
}
int getActiveNode(int source, int sink) {
    for (int i = 1; i < v - 1; i++) {
        if (vert[i].eflow > 0) {
            for (int j = 0; j < v; j++) {
                if (cap[i][j] != 0 || flow[i][j] != 0) {
                    if (cap[i][j] != flow[i][j]) {
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}
bool push(int u) {
    for (int i = 0; i < v; i++) {
        if (cap[u][i] != 0 || flow[u][i] != 0) {
            if (cap[u][i] != flow[u][i]) {
                if (vert[u].ht > vert[i].ht) {
                    int rem = cap[u][i] - flow[u][i];
                    int ef = vert[u].eflow;
                    int fl = min(rem, ef);
                    vert[u].eflow -= fl;
                    vert[i].eflow += fl;
                                        flow[u][i] += fl;
                    flow[i][u] -= fl;
                    return true;
                }
            }
        }
    }
    return false;
}
void relabel(int u) {
    int minh = INT_MAX;
    for (int i = 0; i < v; i++) {
        if (cap[u][i] != 0 || flow[u][i] != 0) {
            if (cap[u][i] != flow[u][i]) {
                minh = min(minh, vert[i].ht);
            }
        }
    }
    if (minh < INT_MAX) {
        vert[u].ht = minh + 1;
    }
}
int maxflow(int source, int sink) {
    preflow(source);
    int u = getActiveNode(source, sink);
    while (u != -1) {
             if (!push(u)) {
            relabel(u);
        }
        u = getActiveNode(source, sink);
    }
    return vert[sink].eflow;
}
int main() {
    cout << "24MAI0114     ABHAYNATH K\n";
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vert = new vertex[v];
    cap = new int *[v];
    for (int i = 0; i < v; i++) {
        cap[i] = new int[v]();
    }
    flow = new int *[v];
    for (int i = 0; i < v; i++) {
        flow[i] = new int[v]();
    }
    for (int i = 0; i < v; i++) {
        vert[i].ht = 0;
        vert[i].eflow = 0;
         }
    cout << "Enter the edges with their capacities (format: from to capacity):" <<
endl;
    int x, y, c;
    for (int i = 0; i < e; i++) {
        cout << "Edge " << i + 1 << ": ";
        cin >> x >> y >> c;
        cap[x][y] = c;
    }
    int source, sink;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the sink vertex: ";
    cin >> sink;
    cout << "The maximum flow from source to sink is: " << maxflow(source,
sink) << endl;
    cout << "\nFlow matrix:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << flow[i][j] << "  ";
        }
        cout << endl;
    }
    for (int i = 0; i < v; i++) {
        delete[] cap[i];
        delete[] flow[i];
    }
    delete[] cap;
delete[] flow;
delete[] vert;
return 0;
}
