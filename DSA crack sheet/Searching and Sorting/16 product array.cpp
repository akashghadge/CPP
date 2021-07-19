/*
Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

 

Example 1:

Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Example 2:

Input:
n = 2
nums[] = {12,0}
Output:
0 12

Your Task:
You do not have to read input. Your task is to complete the function productExceptSelf() that takes array nums[] and n as input parameters and returns a list of n integers denoting the product array P. If the array has only one element the returned list should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.
 

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
 

Constraints:
1 <= n <= 1000
0 <= numsi <= 200
Array may contain duplicates.


*/

/*
1    2   3   4   5
1   2   6   24  120
120 120  60 20   5

*/
#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
void printVector(vector<ll> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
vector<long long> sol(vi &arr)
{
    vector<long long> ans(arr.size(), 1);
    if (arr.size() <= 1)
    {
        return ans;
    }
    vector<long long> l(arr.size(), 1);
    vector<long long> r(arr.size(), 1);

    //setting pre prcessing
    l[0] = arr[0];
    r[arr.size() - 1] = arr[arr.size() - 1];
    for (int i = 1; i < arr.size(); i++)
    {
        l[i] = l[i - 1] * arr[i];
    }
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        r[i] = r[i + 1] * arr[i];
    }
    // printVector(l);
    // printVector(r);
    ans[0] = r[1];
    ans[arr.size() - 1] = l[arr.size() - 2];
    for (int i = 1; i < arr.size() - 1; i++)
    {
        ans[i] = l[i - 1] * r[i + 1];
    }

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
    vector<long long> ans = sol(arr);
    printVector(ans);

    return 0;
}