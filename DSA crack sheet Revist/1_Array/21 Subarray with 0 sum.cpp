/*
either duplicate elements in array or any element is zero
*/
#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
{
    // Your code here
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.find(arr[i]) != st.end())
            return true;
        if (arr[i] == 0)
            return true;
        st.insert(arr[i]);
    }
    return false;
}
int main()
{
}