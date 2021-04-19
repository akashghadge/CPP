#include <iostream>
using namespace std;
#include <unordered_map>
int main()
{
}
int countOccurence(int arr[], int n, int k)
{
    // Your code here
    // there are another two aproches are there
    // sort array then count occurances 1 by 1 in o(n) for find and sort o(nlogn)
    // or traditional o(n2) itrate each element
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int times = n / k;
    int c = 0;
    for (auto val : mp)
    {
        if (val.second > times)
        {
            c++;
        }
    }
    return c;
}