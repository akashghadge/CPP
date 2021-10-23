/*
Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
Keep in mind the following conditions :

Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from him.
Example 1:

Input:
N = 5, K = 1
arr[] = {P, T, T, P, T}
Output: 2
Explanation: Maximum 2 thieves can be 
caught. First policeman catches first thief 
and second police man can catch either second 
or third thief.
Example 2:

Input:
N = 6, K = 2
arr[] = {T, T, P, P, T, P}
Output: 3
Explanation: Maximum 3 thieves can be caught.
Your Task:  
You dont need to read input or print anything. Complete the function catchThieves() that takes n, k and arr[ ] as input parameters and returns the maximum number of thieves that can be caught by the police. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ 100
arr[i] = 'P' or 'T'


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
int catchThieves(char arr[], int n, int k)
{
    int i = 0, j = 0, ans = 0;
    while (i < n and j < n)
    {
        if (arr[i] != 'P')
        {
            while (arr[i] != 'P' and i < n)
                i++;
        }
        if (arr[j] != 'T')
        {
            while (arr[j] != 'T' and j < n)
                j++;
        }
        if ((arr[i] == 'P' and arr[j] == 'T') and abs(i - j) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if ((arr[i] == 'P' and arr[j] == 'T') and abs(i - j) > k)
        {
            if (i > j)
                j++;
            else
                i++;
        }
    }
    return ans;
}
int catchThieves(char arr[], int n, int k)
{
    // Code here
    vector<bool> valid(n, false);
    for (int i = 0; i < n; i++)
        if (arr[i] == 'P')
            valid[i] = true;
    int cacth = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'P')
            continue;
        // go and search for left side first
        int pos = i - 1;
        bool flag = false;
        while (pos >= 0 && pos >= (i - k - 1))
        {
            if (valid[pos])
            {
                valid[pos] = false;
                cacth++;
                flag = true;
                break;
            }
            pos--;
        }
        // if dont have police at left side we go for right side then
        if (!flag)
        {
            pos = i + 1;
            while (pos < n && pos <= (i + k))
            {
                if (valid[pos])
                {
                    valid[pos] = false;
                    cacth++;
                    break;
                }
                pos++;
            }
        }
    }
    return cacth;
}
int main()
{
    FAST;
    // int N = 6, K = 2;
    // char arr[] = {'T', 'T', 'P', 'P', 'T', 'P'};
    // int N = 5, K = 1;
    // char arr[] = {'P', 'T', 'T', 'P', 'T'};
    int N = 10, K = 1;
    char arr[] = {'T', 'T', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'};
    cout << catchThieves(arr, N, K) << en;
    return 0;
}