#include <bits/stdc++.h>
using namespace std;

typedef struct mynode {
    int id, status, pred;
} node;
vector<vector<int>> res;
int n;

void getMatrix() {
    cout << "Enter the number of nodes (n): ";
    cin >> n;
    res.resize(n, vector<int>(n));
    cout << "Enter the capacity matrix (" << n << "x" << n << "):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> res[i][j];
        }
    }
    cout << "\n";
}

bool bfs(vector<node>& vert, node source, node sink) {
    node u;
    int i, j;
    queue<node> q;
    for(i = 0; i < n; i++) {
        vert[i].status = 0;
    }
    q.push(source);
    vert[source.id].status = 1;
    vert[source.id].pred = -1;

    while(!q.empty()) {
        u = q.front();
        q.pop();
        for (j = 0; j < n; j++) {
            if(res[u.id][j] > 0 && vert[j].status == 0) {
                q.push(vert[j]);
                vert[j].status = 1;
                vert[j].pred = u.id;
                if(j == sink.id) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cout << "24MAI0114   ABHAYNATH K\n";
    getMatrix();
    vector<node> vert(n);
    node source, sink;

    for(int i = 0; i < n; i++) {
        vert[i].id = i;
    }
    source.id = 0;
    sink.id = n - 1;
    int totalflow = 0, u, v;

    while(bfs(vert, source, sink)) {
        int augflow = INT_MAX;
        cout << "Path : " << sink.id << " <- ";
        for(int v = sink.id; v != source.id; v = vert[v].pred) {
            u = vert[v].pred;
            cout << u << " <- ";
            augflow = min(augflow, res[u][v]);
        }
        cout << "\nAugflow : " << augflow << endl;
        for(int v = sink.id; v != source.id; v = vert[v].pred) {
            u = vert[v].pred;
            res[u][v] -= augflow;
            res[v][u] += augflow;
        }
        totalflow += augflow;
    }
    cout << "\nResidual Capacity Matrix :\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nMaximum flow : " << totalflow << endl;
    return 0;
}
