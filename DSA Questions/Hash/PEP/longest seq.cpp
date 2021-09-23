#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// pep coding approch
vector<int> pep(vector<int> &arr)
{
    unordered_map<int, bool> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] = true;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(arr[i] - 1) != mp.end())
        {
            mp[arr[i]] = false;
        }
    }

    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        if (!mp[arr[i]])
            continue;
        vector<int> temp;
        int j = 0;
        while (mp.find(arr[i] + j) != mp.end())
        {
            temp.push_back(arr[i] + j);
            j++;
        }
        if (res.size() < temp.size())
            res = temp;
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
    vector<int> arr = {10, 5, 9, 1, 11, 8, 6, 15, 3, 12, 2} ;
    vector<int> res;
    res = pep(arr);
    printVector(res);
    return 0;
}