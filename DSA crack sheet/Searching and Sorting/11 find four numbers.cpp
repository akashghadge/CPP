/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.
Your Task:
You don't need to read input or print anything. Your task is to complete the function fourSum() which takes the array arr[] and the integer k as its input and returns an array containing all the quadruples in a lexicographical manner. Also note that all the quadruples should be internally sorted, ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4.  (In the output each quadruple is separate by $. The printing is done by the driver's code)

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100

*/
#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
// first get two numbers by loop and then use two pointer approch
// here firsly i use set for getting override of duplicates :)(gfg test cases)
vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    // Your code goes here
    sort(arr.begin(), arr.end());
    int size = arr.size();
    set<vector<int>> ans;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int k = j + 1, l = size - 1;
            while (k < l)
            {
                int val = arr[i] + arr[j] + arr[k] + arr[l];
                if (val == target)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                if (val < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    vector<vector<int>> finalAns;
    for (auto val : ans)
    {
        finalAns.push_back(val);
    }
    sort(finalAns.begin(), finalAns.end());
    return finalAns;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}