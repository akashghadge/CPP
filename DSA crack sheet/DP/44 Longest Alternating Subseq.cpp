/*
A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :
x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....
Your task is to find the longest such sequence.

Example 1:

Input: nums = {1,5,4}
Output: 3
Explanation: The entire sequenece is a 
alternating sequence.
Examplae 2:

Input: nums = {1,17,5,10,13,15,10,5,16,8}
Ooutput: 7
Explanation: There are several subsequences
that achieve this length. 
One is {1,17,10,13,10,16,8}.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function AlternatingaMaxLength() which takes the sequence  nums as input parameter and returns the maximum length of alternating sequence.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 105


*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int AlternatingaMaxLength(vector<int> &nums)
    {
        // Code here
        int n = nums.size();
        int greater = 1;
        int lesser = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                greater = lesser + 1;
            }
            else if (nums[i - 1] < nums[i])
            {
                lesser = greater + 1;
            }
            else
                continue;
        }
        return max(greater, lesser);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.AlternatingaMaxLength(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends