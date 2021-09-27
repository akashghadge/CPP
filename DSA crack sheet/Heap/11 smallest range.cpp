/*
Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, find the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.
Example 2:

Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9
Your Task :

Complete the function findSmallestRange() that receives array , array size n and k as parameters and returns the output range (as a pair in cpp and array of size 2 in java and python)

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)

Constraints:
1 <= K,N <= 500
1 <= a[ i ] <= 105

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
const int N = 100;
class Solution
{
public:
    struct ListData
    {
        int index;
        int val;
        int list_num;
        ListData(int num, int i, int v)
        {
            index = i;
            val = v;
            list_num = num;
        }
    };

    class cmpListData
    {
    public:
        bool operator()(ListData &p1, ListData &p2)
        {
            return p1.val > p2.val;
        }
    };
    pair<int, int> findSmallestRange(int lists[][N], int n, int k)
    {
        //code here
        vector<int> mergedList;
        priority_queue<ListData, vector<ListData>, cmpListData> pq;
        int maxNum = INT_MIN;
        int minDiff = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            ListData *lnew = new ListData(i, 0, lists[i][0]);
            maxNum = max(maxNum, lnew->val);
            pq.push(*lnew);
        }
        pair<int, int> ans = {0, 0};
        while (pq.size() > 0)
        {
            ListData l = pq.top();
            if (minDiff > maxNum - l.val)
            {
                minDiff = maxNum - l.val;
                ans.first = l.val;
                ans.second = maxNum;
            }
            pq.pop();
            l.index++;
            if (l.index < n)
            {
                l.val = lists[l.list_num][l.index];
                maxNum = max(l.val, maxNum);
                pq.push(l);
            }
            // break on last or it will get max as last elememtn and min also last so min max so range is 1
            else
                break;
        }
        return ans;
    }
};
int main()
{
    FAST;

    return 0;
}