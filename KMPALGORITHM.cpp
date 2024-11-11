#include<bits/stdc++.h>
using namespace std;

// Function to calculate the Longest Prefix Suffix (LPS) array
void calcLPS (string P, int LPS[])
{
    LPS[0] = 0;  // The first value is always 0
    int i = 0, j = 1;

    while(j < P.length())
    {
        if(P[i] == P[j])
        {
            LPS[j] = i + 1; // Extend the current match
            i++;
            j++;
        }
        else
        {
            if(i == 0)
            {
                LPS[j] = 0;  // If no prefix match, set LPS[j] to 0
                j++;
            }
            else
            {
                i = LPS[i - 1];  // Try with the previous best match
            }
        }
    }
}

int main()
{
    // Input main string and pattern from the user
    string S, P;

    cout << "Enter the main string: ";
    cin >> S;

    cout << "Enter the pattern to search: ";
    cin >> P;

    int plen = P.length();
    int slen = S.length();

    // Create LPS array of size equal to the length of the pattern
    int LPS[plen];

    // Calculate the LPS array for the pattern
    calcLPS(P, LPS);

    int i = 0, j = 0;  // i for S (main string) and j for P (pattern)

    // KMP search algorithm
    while(i < slen)
    {
        if(P[j] == S[i])
        {
            i++;
            j++;
        }

        if(j == plen)  // A match is found when j reaches the length of the pattern
        {
            cout << (i - plen) << " is the index.\n";  // Print the start index of the match
            j = LPS[j - 1];  // Update j using LPS array to continue searching
        }
        else if(i < slen && P[j] != S[i])  // Mismatch after j matches
        {
            if(j == 0)
            {
                i++;  // If no prefix match, just move to the next character in S
            }
            else
            {
                j = LPS[j - 1];  // Use the LPS array to avoid unnecessary comparisons
            }
        }
    }

    return 0;
}
