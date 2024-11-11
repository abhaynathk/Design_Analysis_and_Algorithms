#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

// Function to check orientation of the ordered triplet (p, q, r).
// It returns:
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Function to check if point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

// Function that returns true if the line segment 'p1q1' and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4) return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 // p1, q1 and p2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

int main() {
    cout << "24MAI0114   ABHAYNATH K\n";

    Point p1, q1, p2, q2;
    // Taking input for the first line segment
    cout << "Enter coordinates of the first line segment:\n";
    cout << "Enter coordinates of the first point (x1, y1): ";
    cin >> p1.x >> p1.y;
    cout << "Enter coordinates of the second point (x2, y2): ";
    cin >> q1.x >> q1.y;

    // Taking input for the second line segment
    cout << "Enter coordinates of the second line segment:\n";
    cout << "Enter coordinates of the first point (x3, y3): ";
    cin >> p2.x >> p2.y;
    cout << "Enter coordinates of the second point (x4, y4): ";
    cin >> q2.x >> q2.y;

    // Check if the segments intersect
    if (doIntersect(p1, q1, p2, q2)) {
        cout << "The line segments intersect." << endl;
    } else {
        cout << "The line segments do not intersect." << endl;
    }

    return 0;
}
