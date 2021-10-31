/*
function only have index and array
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
vector<int> print(int arr[], int i, int n, int target)
{
    if (i == n)
    {
        vector<int> res;
        return res;
    }
    vector<int> res = print(arr, i + 1, n, target);
    if (arr[i] == target)
        res.push_back(i);
    return res;
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
    FAST;
    int n = 9;
    int arr[] = {10, 2, 4, 5, 333, 2, 3, 333, 44};
    vector<int> res = print(arr, 0, n, 333);
    printVector(res);
    return 0;
}