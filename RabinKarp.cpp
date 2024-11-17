#include<bits/stdc++.h>
using namespace std;

#define prime 13

int main() {
    string s, p;
    cout<<"24MAI0114     ABHAYNATH K\n"<<endl;
    cout << "Enter the word: \n";
    cin >> s;
    cout << "Enter the pattern to find: \n";
    cin >> p;

    int slen = s.length();
    int plen = p.length();
    int flag = 0, h = 1, maxchar = 10;

    // Calculating the value of h
    for (int i = 1; i < plen; i++) {
        h = (h * maxchar) % prime;
    }

    int sh = 0, ph = 0;
    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < plen; i++) {
        sh = (sh * maxchar + (s[i] - '0')) % prime;
        ph = (ph * maxchar + (p[i] - '0')) % prime;
    }

    // Sliding over the text
    for (int i = 0; i <= slen - plen; i++) {
        // Check the hash values of current window of text and pattern
        if (sh == ph) {
            // Check character by character if the hashes match
            int j;
            for (j = 0; j < plen; j++) {
                if (s[i + j] != p[j]) break;
            }

            if (j == plen) {
                cout << "Pattern found at index " << i << endl;
                flag = 1;
            }
        }

        // Calculate hash for next window of text
        if (i < slen - plen) {
            sh = (sh - (s[i] - '0') * h) * maxchar + (s[i + plen] - '0');
            sh = (sh % prime + prime) % prime;  // Adjust if the hash becomes negative
        }
    }

    if (!flag) {
        cout << "Pattern not found" << endl;
    }

    return 0;
}
