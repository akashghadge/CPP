/*
Given a list(Arr) of N integers, print sums of all subsets in it. Output should be printed in increasing order of sums.

Example 1:

Input:
N = 2
Arr = [2, 3]
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
Example 2:

Input:
N = 3
Arr = [5, 2, 1]
Output:
0 1 2 3 5 6 7 8
Your Task:  
You don't need to read input or print anything. Your task is to complete the function subsetSum() which takes a list/vector and an integer N as an input parameter and return the list/vector of all the subset sums in increasing order.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)
*/
#include <iostream>
using namespace std;
#include "vector"
#include "algorithm"
int util(vector<int> arr, int i, int currentSum, vector<int> &ans)
{
    if (i == arr.size())
    {
        ans.push_back(currentSum);
        return 0;
    }
    util(arr, i + 1, currentSum, ans);
    util(arr, i + 1, currentSum + arr[i], ans);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ans;
    util(arr, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
void printVector(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "At Index " << i << " Vector have : " << vec[i] << endl;
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 2};
    vector<int> ans = subsetSums(arr, arr.size());
    printVector(ans);
}