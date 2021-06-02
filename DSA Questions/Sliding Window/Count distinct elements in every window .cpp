/*
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.
Example 2:

Input:
N = 3, K = 2
A[] = {4,1,1}
Output: 2 1
Your Task:
Your task is to complete the function countDistinct() which takes the array A[], the size of the array(N) and the window size(K) as inputs and returns an array containing the count of distinct elements in every contiguous window of size K in the array A[].

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= K <= 105
1 <= A[i] <= 105 , for each valid i


*/

#include <bits/stdc++.h>
#define en "\n"
using namespace std;
// accurate code
class Solution
{
public:
    vector<int> countDistinct(int A[], int n, int k)
    {
        //code here.
        unordered_map<int, int> w;
        vector<int> ans;
        int dis_ele = 0;
        for (int i = 0; i < k; i++)
        {
            if (w[A[i]] == 0)
            {
                dis_ele++;
            }
            w[A[i]] += 1;
        }
        ans.push_back(dis_ele); //for first window
        for (int i = k; i < n; i++)
        {
            if (w[A[i - k]] == 1)
            {
                dis_ele--;
            }
            w[A[i - k]] -= 1;

            if (w[A[i]] == 0)
            {
                dis_ele++;
            }
            w[A[i]]++;
            ans.push_back(dis_ele);
        }
        return ans;
    }
};
class Solution
{
public:
    // brute force
    vector<int>
    countDistinct(int A[], int n, int k)
    {
        //code here.
        unordered_map<int, int> mp;
        int dis_ele;
        vector<int> res;
        for (int i = 0; i < n - k + 1; i++)
        {
            mp.clear();
            dis_ele = k;
            for (int j = i; j < i + k; j++)
            {
                if (mp.find(A[j]) != mp.end())
                {
                    dis_ele--;
                }
                else
                {
                    mp[A[j]]++;
                }
            }

            res.push_back(dis_ele);
        }
        return res;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}