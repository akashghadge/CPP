#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
/*
for learing this algo consider each time go and serch for minimum element and then place it to sorted side 
sorted list | unsorted list
|5 4 1 2 3
1 | 4 5 2 3
1 2 | 5 4 3
1 2 3 | 4 5
1 2 3 4 |5
1 2 3 4 5 | 
*/
void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void selectionSort(vector<int> &arr, bool flag)
{
    if (arr.size() == 1)
    {
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (flag && arr[min] > arr[j])
            {
                min = j;
            }
            else if (!flag && arr[min] < arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
int main()
{
    /* intial setup */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* array input*/
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    printVector(arr);
    selectionSort(arr, true);
    printVector(arr);
    selectionSort(arr, false);
    printVector(arr);
}