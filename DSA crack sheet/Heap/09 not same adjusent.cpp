/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
struct cmp
{
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        return a.second < b.second;
    }
};

class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> map;
        int l = s.length();
        for (int i = 0; i < l; ++i)
        {
            ++map[s[i]];
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq; // you have to make a new struct
                                                                          // to order the priority queue
                                                                          // by second element of pair
        for (auto x : map)
        {
            pq.push({x.first, x.second});
        }

        string str = "";

        int upper = (l / 2) + 1; // we are setting the upper limit for the character with greater frequency
                                 // if the frequency is greator than the upper limit than we return ""
        if (l % 2 != 0)
        {
            ++upper;
        }
        if (pq.top().second >= upper)
        { // top element of pq is the character with greatest frequency
            return str;
        }
        pair<char, int> prev = {'#', 0};

        for (int k = 0; k < s.length(); ++k)
        {
            pair<char, int> p = pq.top();

            if (p.second > 0)
            {
                str += p.first;
                --p.second;
            }
            pq.pop();
            pq.push(prev);
            prev = p;
        }

        return str;
    }
};
int main()
{
    FAST;

    return 0;
}