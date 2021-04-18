#include <iostream>
using namespace std;
#include <unordered_map>
int firstRepeated(int arr[], int n)
{
    //code here
    // sort(arr,arr+n);
    unordered_map<int, int> mp;
    int min = 1000;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            if (min > mp[arr[i]])
            {
                min = mp[arr[i]];
            }
        }
        mp[arr[i]] = i;
    }
    if (min == 1000)
    {
        return -1;
    }
    else
    {
        return min + 1;
    }
}
int main()
{
}