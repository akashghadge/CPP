/*
Given an array arr[ ] of size N, write a program that returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.

Example 1:

Input:
N = 3
arr = {2, 4, 3}
Output: 1
Explaination: Given arr[] can represent
preorder traversal of following BST:
               2
                \
                 4
                /
               3
Example 2:

Input:
N = 3
Arr = {2, 4, 1}
Output: 0
Explaination: Given arr[] cannot represent
preorder traversal of a BST.
Your Task:
You don't need to read input or print anything. Your task is to complete the function canRepresentBST() which takes the array arr[] and its size N as input parameters and returns 1 if given array can represent preorder traversal of a BST, else returns 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
1 ≤ arr[i] ≤ 105


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
    // using stack
    int canRepresentBST(int arr[], int N)
    {
        // code here
        stack<int> st;
        int root = INT_MIN;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] < root)
                return false;
            while (!st.empty() && arr[i] > st.top())
            {
                root = st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        return true;
    }
    // build and check is array is completely build or not
    void helper(int arr[], int *ptr, int N, int min, int max)
    {
        if (*ptr >= N)
            return;
        if (min <= arr[*ptr] && arr[*ptr] <= max)
        {
            int rootData = arr[*ptr];
            *ptr = *ptr + 1;
            if (*ptr < N)
            {
                helper(arr, ptr, N, min, rootData);
            }
            if (*ptr < N)
            {
                helper(arr, ptr, N, rootData, max);
            }
        }
        return;
    }
    int canRepresentBST(int arr[], int N)
    {
        // code here
        int ptr = 0;
        helper(arr, &ptr, N, INT_MIN, INT_MAX);
        return ptr == N;
    }
};
int main()
{
    FAST;

    return 0;
}