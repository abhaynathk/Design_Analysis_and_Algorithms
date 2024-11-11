#include <iostream>
#include <queue>
using namespace std;
typedef struct print {
int x, y;
} pt;
int dir(pt p, pt q, pt r) {
     return ((r.x - p.x) * (q.y - p.y)) - ((r.y - p.y) * (q.x - p.x));
}

void convex(pt p[], int n) {
    if (n < 3) {
        cout << "Convex hull is not possible with less than 3 points.\n";
        return;
    }
    bool inc[n] = {false};
    int left = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].x < p[left].x)
            left = i;
    }

    int prev = left, curr;
    do {
        inc[prev] = true;
        curr = (prev + 1) % n;

        for (int i = 0; i < n; i++) {
            if (dir(p[prev], p[curr], p[i]) < 0) {
                curr = i;
            }
        }
        prev = curr;
        } while (prev != left);
cout << "Points in Convex Hull:\n";
for (int i = 0; i < n; i++) {
if (inc[i])
cout << "(" << p[i].x << ", " << p[i].y << ")\n";
}
}
int main() {
int n;
cout<<"24MAI0114    ABHAYNATH K:\n";
cout << "Enter number of points: ";
cin >> n;
pt p[n];
cout << "Enter the points (x y):\n";
for (int i = 0; i < n; i++) {
cin >> p[i].x >> p[i].y;
}
convex(p, n);
return 0;
}
