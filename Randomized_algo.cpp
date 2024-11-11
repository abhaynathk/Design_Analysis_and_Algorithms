#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Candidate {
    int rank;
    int inter_status = 0;
};

int main() {
    cout<<"24MAI0114     ABHAYNATH K\n";
    int n, no_of_hires = 0;
    cout << "Enter the number of candidates:\n";
    cin >> n;

    vector<Candidate> candidates(n);
    cout << "Enter the rank of each candidate:\n";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i].rank;
    }

    int best = -1;
    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < n; i++) {
        int index;
        do {
            index = rand() % n; // Select a random index
        } while (candidates[index].inter_status == 1); // Ensure not already selected

        candidates[index].inter_status = 1; // Mark as interviewed

        // Update the best candidate if the current one has a higher rank
        if (best == -1 || candidates[index].rank > candidates[best].rank) {
            best = index;
            no_of_hires++;
        }
    }

    cout << "Number of hires: " << no_of_hires << endl;
    cout << "Best candidate index: " << best << ", Rank: " << candidates[best].rank << endl;

    return 0;
}
