/*
Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
Note: All elements of this array should be part of exactly one partition.

Example 1:

Input: 
N = 5
a[] = {2,1,4,5,6}
K = 3
Output: 
1
Explanation: we can divide above array 
into 3 parts with equal sum as (2, 4), 
(1, 5), (6)
Example 2:

Input: 
N = 5 
a[] = {2,1,5,5,6}
K = 3
Output: 
0
Explanation: It is not possible to divide
above array into 3 parts with equal sum.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isKPartitionPossible() which takes the array a[], the size of the array N, and the value of K as inputs and returns true(same as 1) if possible, otherwise false(same as 0).

Expected Time Complexity: O(N*2N).
Expected Auxiliary Space: O(2N).

Constraints:
1 ≤ K ≤ N ≤ 10
1 ≤ a[i] ≤ 100


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

bool flag = false;
bool valid(vector<vector<int>> subsets)
{
    int sum = accumulate(subsets[0].begin(), subsets[0].end(), 0);
    for (auto list : subsets)
    {
        if (list.size() == 0)
            return false;
        int curr_sum = accumulate(list.begin(), list.end(), 0);
        if (curr_sum != sum)
            return false;
    }
    return true;
}
void util(int curr, int n, int a[], int k, vector<vector<int>> subsets)
{
    if (flag)
        return;
    if (curr == n)
    {
        if (valid(subsets))
        {
            flag = true;
        }
        return;
    }
    for (int i = 0; i < k; i++)
    {
        if (subsets[i].size() == 0)
        {
            subsets[i].push_back(a[curr]);
            util(curr + 1, n, a, k, subsets);
            subsets[i].pop_back();
            break;
        }
        else
        {
            subsets[i].push_back(a[curr]);
            util(curr + 1, n, a, k, subsets);
            subsets[i].pop_back();
        }
    }
}
bool isKPartitionPossible(int a[], int n, int k)
{
    //Your code here
    flag = false;
    vector<vector<int>> subsets(k);
    util(0, n, a, k, subsets);
    return flag;
}
int main()
{
    FAST;

    return 0;
}