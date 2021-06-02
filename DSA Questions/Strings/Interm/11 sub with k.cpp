/*
Given a string and an integer k, find number of substrings in which all the different characters occurs exactly k times. 

Examples: 

Input : s = "aabbcc"
        k = 2 
Output : 6
The substrings are aa, bb, cc,
aabb, bbcc and aabbcc.

Input : s = "aabccc"
        k = 2
Output : 3
There are three substrings aa, 
cc and cc
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
The idea is to traverse through all substrings. We fix a starting point, traverse through all substrings starring with the picked point, we keep incrementing frequencies of all characters. If all frequencies become k, we increment result. If count of any frequency becomes more than k, we break and change starting point. 

*/
// C++ program to count number of substrings
// with counts of distinct characters as k.
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// Returns true if all values
// in freq[] are either 0 or k.
bool check(int freq[], int k)
{
    for (int i = 0; i < MAX_CHAR; i++)
        if (freq[i] && freq[i] != k)
            return false;
    return true;
}

// Returns count of substrings where frequency
// of every present character is k
int substrings(string s, int k)
{
    int res = 0; // Initialize result

    // Pick a starting point
    for (int i = 0; s[i]; i++)
    {

        // Initialize all frequencies as 0
        // for this starting point
        int freq[MAX_CHAR] = {0};

        // One by one pick ending points
        for (int j = i; s[j]; j++)
        {

            // Increment frequency of current char
            int index = s[j] - 'a';
            freq[index]++;

            // If frequency becomes more than
            // k, we can't have more substrings
            // starting with i
            if (freq[index] > k)
                break;

            // If frequency becomes k, then check
            // other frequencies as well.
            else if (freq[index] == k &&
                     check(freq, k) == true)
                res++;
        }
    }
    return res;
}

// Driver code
int main()
{
    string s = "aabbcc";
    int k = 2;
    cout << substrings(s, k) << endl;

    s = "aabbc";
    k = 2;
    cout << substrings(s, k) << endl;
}
