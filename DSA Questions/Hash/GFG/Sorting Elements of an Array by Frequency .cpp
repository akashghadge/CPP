/*
Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Example 1:

Input:
N = 5
A[] = {5,5,4,6,4}
Output: 4 4 5 5 6
Explanation: The highest frequency here is
2. Both 5 and 4 have that frequency. Now
since the frequencies are same then 
smallerelement comes first. So 4 4 comes 
firstthen comes 5 5. Finally comes 6.
The output is 4 4 5 5 6.
Example 2:

Input:
N = 5
A[] = {9,9,9,2,5}
Output: 9 9 9 2 5
Explanation: The highest frequency here is
3. The element 9 has the highest frequency
So 9 9 9 comes first. Now both 2 and 5
have same frequency. So we print smaller
element first.
The output is 9 9 9 2 5.
Your Task:

You only need to complete the function sortByFreq that takes arr, and n as parameters and returns the sorted array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N). 

Constraints:
1 ≤ N ≤ 105
1 ≤ Ai ≤ 105 


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
vector<int> sortByFreq(int arr[], int n)
{
    // getting all freq
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    // store it to vector in pair forms so we can sort using comparator
    vector<pair<int, int>> temp;
    for (auto p : mp)
    {
        pair<int, int> pt = {p.first, p.second};
        temp.push_back(pt);
    }

    // custom sort
    sort(temp.begin(), temp.end(), [](pair<int, int> &p1, pair<int, int> &p2)
         {
             if (p1.second == p2.second)
             {
                 return p1.first < p2.first;
             }
             return p1.second > p2.second;
         });

    // final res
    vector<int> res;
    for (auto val : temp)
    {
        vector<int> t(val.second, val.first);
        res.insert(res.end(), t.begin(), t.end());
    }
    return res;
}
int main()
{
    FAST;

    return 0;
}