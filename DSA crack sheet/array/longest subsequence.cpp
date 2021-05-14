/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105


*/
// the idea behind solution is use hashing to store all occurances
// after that check if next ocurrance is present or not in hassing 
#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int N)
{
    //Your code here
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        mp[arr[i]] = 1;
    }
    int mc = 0;
    for (int i = 0; i < N; i++)
    {
        int c = 1;
        int val = arr[i] + 1;
        if (mp.find(val - 2) != mp.end())
        {
            continue;
        }
        while (mp.find(val) != mp.end())
        {
            // cout<<"for "<<arr[i]<<" "<<c<<endl;
            val++;
            c++;
        }
        mc = max(c, mc);
    }
    return mc;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}