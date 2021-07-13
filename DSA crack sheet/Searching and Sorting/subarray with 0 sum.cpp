/*
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array arr and its size n as input parameters and returns the total number of sub-arrays with 0 sum. 
 

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
 

Constraints:    
1<= n <= 107
-1010 <= arri <= 1010


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// Function to print all subarrays in the array which
// has sum 0
vector<pair<int, int>> findSubArrays(vector<int> arr, int n)
{
    // create an empty map
    unordered_map<int, vector<int>> map;

    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector<pair<int, int>> out;

    // Maintains sum of elements so far
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // add current element to sum
        sum += arr[i];

        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum == 0)
            out.push_back(make_pair(0, i));

        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        // Important - no else
        map[sum].push_back(i);
    }

    // return output vector
    return out;
}
/* ---------------> Que solution <------------*/
ll findSubarray(vector<ll> arr, int n)
{
    //code here
    int sum = 0;
    int ans = 0;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            ans += 1;
        }
        if (mp.find(sum) != mp.end())
        {
            ans += mp[sum].size();
        }
        mp[sum].push_back(i);
    }
    return ans;
}
// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out)
{
    for (auto it = out.begin(); it != out.end(); it++)
        cout << "Subarray found from Index " << it->first << " to " << it->second << endl;
}

// Driver code
int main()
{
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<pair<int, int>> out = findSubArrays(arr, n);
    // if we didn’t find any subarray with 0 sum,
    // then subarray doesn’t exists
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out);

    return 0;
}
