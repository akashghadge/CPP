/*
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5. 
 

Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6 

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.
Note: If the number x is not found in the array just return both index as -1.

 

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

 

Constraints:
1 ≤ N ≤ 107


*/

// accurate code
/*
count occ  in sorted array
1 2 3 3 3 3 4 for 3
3 have 4 occ
*/
/*
Here approch find lower and higher index useing binary search
for lower index if we encounter number we just store it in varible as it is a possible answer and reduce search space by high =mid -1
        
*/
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
vi sol(vi &, int);
int solOcc(vi &arr, int target)
{
    vi ans = sol(arr, target);
    return (ans[1] - ans[0]) + 1;
}
vi sol(vi &arr, int target)
{
    vi ans(2);
    int low = 0;
    int high = arr.size();
    int mid = 0;
    int lowerIndex = -1;
    while (high - low > 0)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            lowerIndex = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // cout << lowerIndex << en;

    // for upper index
    low = 0;
    high = arr.size();
    int upperIndex = -1;
    while (high - low > 0)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            upperIndex = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << lowerIndex << en;
    cout << upperIndex << en;
    ans[0] = lowerIndex;
    ans[1] = upperIndex;
    return ans;
}
int main()
{
    FAST;
    int N;
    cin >> N;
    vi arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vi ans = sol(arr, target);
    cout << "first occ : " << ans[0] << en;
    cout << "last occ : " << ans[1] << en;

    int occ = solOcc(arr, target);
    cout << occ << en;
    return 0;
} 