/*
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 


Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 105
1 ≤ numsi ≤ 106


*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/*
    here basic approch is first sort vector of pairs here pair consist of index and value
    sort according to first parameter i.e value here
    then compare it's current sorted index and index in original vector
    if position is correct i.e orignal array index and sorted array index then skip
    other wise make swap with it's accurate index 
    */
int minSwaps(vector<int> &arr)
{
    // Code here
    int swaps = 0;
    int size = arr.size();
    vector<pair<int, int>> pairs;
    for (int i = 0; i < arr.size(); i++)
    {
        pair<int, int> p = make_pair(arr[i], i);
        pairs.push_back(p);
    }
    sort(pairs.begin(), pairs.end());

    for (int i = 0; i < size;)
    {
        if (pairs[i].second == i)
        {
            i++;
            continue;
        }
        swap(pairs[i], pairs[pairs[i].second]);
        swaps++;
    }
    return swaps;
}
int main()
{
    FAST;

    return 0;
}