/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000

View Bookmarked Problems

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
    bool flag = false;
    void sol(int curr, int total, int arr[], vector<int> slot1, vector<int> slot2)
    {
        if (curr == total)
        {
            int sum1 = accumulate(slot1.begin(), slot1.end(), 0);
            int sum2 = accumulate(slot2.begin(), slot2.end(), 0);
            if (sum1 == sum2)
                flag = true;
            return;
        }
        slot1.push_back(arr[curr]);
        sol(curr + 1, total, arr, slot1, slot2);
        slot1.pop_back();
        slot2.push_back(arr[curr]);
        sol(curr + 1, total, arr, slot1, slot2);
        slot2.pop_back();
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        vector<int> slot1;
        vector<int> slot2;
        sol(0, N, arr, slot1, slot2);
        return flag;
    }
};
int main()
{
    FAST;

    return 0;
}