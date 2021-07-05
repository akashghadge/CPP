#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;

int ser(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int target;
    vector<int> arr(N);
    cin >> target;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << binary_search(arr.begin(), arr.end(), target) << en;
    cout << ser(arr, target) << en;
    return 0;
}