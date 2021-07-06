#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
void bubbleSort(vector<int> &arr, bool flag)
{
    if (arr.size() == 1)
    {
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (flag && arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            if (!flag && arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
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
    bubbleSort(arr, true);
    printVector(arr);
    bubbleSort(arr, false);
    printVector(arr);
}