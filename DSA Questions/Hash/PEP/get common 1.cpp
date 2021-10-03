/*
ar1     1 1 1 2 3 4 
ar2     1 1 2 2 3 5

output 
1 2 3
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

vector<int> common(int arr1[], int size1, int arr2[], int size2)
{
    vector<int> res; 
    unordered_map<int, int> mp;
    for (int i = 0; i < size1; i++)
    {
        mp[arr1[i]]++;
    }

    for (int i = 0; i < size2; i++)
    {
        if (mp.find(arr2[i]) != mp.end())
        {
            res.push_back(arr2[i]);
            mp.erase(arr2[i]);
        }
    }
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
    int arr1[] = {1, 1, 1, 2, 3, 4};
    int arr2[] = {1, 1, 1, 2, 3, 5};
    vector<int> res = common(arr1, 6, arr2, 6);
    printVector(res);
    return 0;
}