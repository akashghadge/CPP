/*
Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
Examples: 
 

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     Sum of all min & max = 6 + 4 + 4 + 4 
                          = 18               

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
class Solution
{
public:
    int minValue(string s, int k)
    {
        // code here
        unordered_map<char, int> mp;
        for (char ch : s)
        {
            mp[ch]++;
        }
        priority_queue<int> pq;
        for (auto val : mp)
        {
            pq.push(val.second);
        }
        for (int i = 0; i < k; i++)
        {
            int val = pq.top();
            pq.pop();
            val--;
            pq.push(val);
        }
        int ans = 0;
        while (!pq.empty())
        {
            ans += (pq.top() * pq.top());
            pq.pop();
        }
        return ans;
    }
};
int main()
{
    FAST;

    return 0;
}