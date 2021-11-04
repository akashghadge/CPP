/*

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void helper(vector<int> arr, int index, int currSum, int target, vector<int> temp, vector<vector<int>> &res)
{
    if (index == arr.size())
    {
        if (currSum == target)
        {
            res.push_back(temp);
        }
        return;
    }
    helper(arr, index + 1, currSum, target, temp, res);
    temp.push_back(arr[index]);
    currSum += arr[index];
    helper(arr, index + 1, currSum, target, temp, res);
}
vector<vector<int>> sol(vector<int> arr, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    helper(arr, 0, 0, target, temp, res);
    return res;
}
void printVector(vector<vector<int>> vec)
{
    for (auto list : vec)
    {
        for (auto val : list)
        {
            cout << val << " ";
        }
        cout << en;
    }
    cout << endl;
}
int main()
{
    FAST;
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 60;
    vector<vector<int>> res = sol(arr, target);
    printVector(res);
    return 0;
}