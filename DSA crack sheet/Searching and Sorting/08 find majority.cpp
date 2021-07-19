/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output:
-1
Explanation:
Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output:
3
Explanation:
Since, 3 is present more
than N/2 times, so it is 
the majority element.

Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
 

Constraints:
1 <= N <= 107
0 <= Ai <= 106
*/
#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {

        // your code here
        if (size == 1)
        {
            return a[0];
        }
        sort(a, a + size);
        int i = 0;
        int count = 0;
        while (i < size)
        {
            if (a[i] == a[i + 1])
            {
                count++;
                // cout<<count<<endl;
                if ((size / 2) <= count)
                {
                    return a[i];
                    break;
                }
            }
            else
            {
                count = 0;
            }
            i++;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}