/*

*/
#include <bits/stdc++.h>
using namespace std;
void segregateElements(int arr[], int n)
{
    // Your code goes here
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
        if (0 < arr[i])
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    int i = 0, j = 0;
    while (i < pos.size())
        arr[i] = pos[i++];
    while (i < n)
        arr[i++] = neg[j++];
}
int main()
{
}