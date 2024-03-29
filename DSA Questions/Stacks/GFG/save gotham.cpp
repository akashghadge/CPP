/*
Gotham has been attacked by Joker . Bruce Wayne has deployed an automatic machine gun at each tower of Gotham.
All the towers in Gotham are in a straight line.
You are given no of towers 'n' followed by the height of 'n' towers.
For every tower(p), find the height of the closest tower (towards the right), greater than the height of the tower(p).
Now, the Print sum of all such heights (mod 1000000001).

Note: If for a tower(k), no such tower exists then take its height as 0.

Example 1:

â€‹Input : arr[]= {112, 133, 161, 311, 122, 
                    512, 1212, 0, 19212}
Output : 41265
Explanation:
nextgreater(112) : 133
nextgreater(133) : 161
nextgreater(161) : 311
nextgreater(311) : 512
nextgreater(122) : 512
nextgreater(512) : 1212
nextgreater(1212) : 19212
nextgreater(0) : 19212
nextgreater(19212) : 0
add = 133+161+311+512+512+1212+19212+19212+0 
add = 41265.

â€‹Example 2:

Input : arr[] = {5, 9, 7, 6} 
Output :  9

 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function save_gotham() that takes an array (arr), sizeOfArray (n), and return the sum of next greater element of every element. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1 ≤ N ≤ 105
0 ≤ A[i] ≤ 104


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
int save_gotham(int arr[], int n)
{
    // Complete the function
    stack<int> st;
    int ans = 0;
    const int M = 1e9 + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            ans = (ans % M) + (st.top() % M);
        }
        st.push(arr[i]);
    }
    return ans;
}
int main()
{
    FAST;

    return 0;
}