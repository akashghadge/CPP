/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getPairsCount() which takes arr[], n and k as input parameters and returns the number of pairs that have sum K.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/
#include <iostream>
using namespace std;
#include <unordered_map>
int getPairsCount(int arr[], int n, int k)
{
    // code here
    // here in o(n2) is que done easily
    // so we need trade of time with space
    // here we sotre the frequency of each number first loop
    // we set twice_count because we get pair i.e for 2 numbers codition is satisfy
    // here we cheak weather number i.e k-arr[i] have sum count or not and add it
    // some time for number which is k/2 we get extra count so we decrement it
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int twice_count = 0;
    for (int i = 0; i < n; i++)
    {
        twice_count += mp[k - arr[i]];
        if (k - arr[i] == arr[i])
        {
            twice_count--;
        }
    }
    return twice_count / 2;
}
int main()
{
}