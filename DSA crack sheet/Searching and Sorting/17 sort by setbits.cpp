/*
Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, sort according to their position in the original array i.e., a stable sort.

 
Example 1:
Input: 
arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
Output:
15 7 5 3 9 6 2 4 32
Explanation:
The integers in their binary
representation are:
15 - 1111
7  - 0111
5  - 0101
3  - 0011
9  - 1001
6  - 0110
2  - 0010
4  - 0100
32 - 10000
hence the non-increasing sorted order is:
{15}, {7}, {5, 3, 9, 6}, {2, 4, 32}
 
Example 2:
Input: 
arr[] = {1, 2, 3, 4, 5, 6};
Output: 
3 5 6 1 2 4
Explanation:
3  - 0110
5  - 0101
6  - 0110
1  - 0001
2  - 0010
4  - 0100
hence the non-increasing sorted order is
{3, 5, 6}, {1, 2, 4}


Your Task:
You don't need to print anything, printing is done by the driver code itself. You just need to complete the function sortBySetBitCount() which takes the array arr[] and its size N as inputs and sort the array arr[] inplace. Use of extra space is prohibited.
 

Expected Time Complexity: O(N.log(N))
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 106


*/

/*
1 use aux array to count bits and sort aux and orginaal array
2 use std::sort with comparitor
3 use counting sort as we have only 32 bit to store
*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}
bool compareBits(int a, int b)
{
    int c1 = countBits(a);
    int c2 = countBits(b);
    if (c1 <= c2)
    {
        return false;
    }
    return true;
}
void sortBySetBitCount(int arr[], int n)
{
    // Your code goes here
    sort(arr, arr + n, compareBits);
}
void sortBySetBitCountWithCountingSort(int arr[], int n)
{
    // Your code goes here
    vector<vector<int>> count(32);
    int setbitcount = 0;
    for (int i = 0; i < n; i++)
    {
        setbitcount = countBits(arr[i]);
        count[setbitcount].push_back(arr[i]);
    }

    int j = 0; // Used as an index in final sorted array

    // Traverse through all bit counts (Note that we
    // sort array in decreasing order)
    for (int i = 31; i >= 0; i--)
    {
        vector<int> v1 = count[i];
        for (int i = 0; i < v1.size(); i++)
            arr[j++] = v1[i];
    }
}
void printVector(int *vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main()
{
    FAST;
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    printVector(arr, N);
    sortBySetBitCount(arr, N);
    printVector(arr, N);
    return 0;
}