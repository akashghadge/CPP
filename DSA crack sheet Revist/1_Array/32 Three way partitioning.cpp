/*

*/
#include <bits/stdc++.h>
using namespace std;
void threeWayPartition(vector<int> &arr, int a, int b)
{
    // code here
    // dutch flag appraoch
    int n = arr.size();
    int i = 0, mid = 0, j = n - 1;
    while (mid <= j)
    {
        if (arr[mid] < a)
        {
            swap(arr[i++], arr[mid++]);
        }
        else if (arr[mid] <= b)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[j--]);
        }
    }
}

int main()
{
}