#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
/*
    for insertion sort we just make two sublist 
    sorted | unsorted
    we pick one element from sorted list and place it it's correct place in sorted list
    i.e
    sorted | unsorted
    5 | 4 3 1 2
    pick 4
    4 5 | 3 1 2
    pick 3
    3 4 5 | 1 2
    pick 1
    1 3 4 5 | 2
    pick 2
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
void insertionSort(vector<int> &arr, bool flag)
{
    if (arr.size() == 1)
    {
        return;
    }
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (flag && j >= 0 && arr[j] > temp)
        {
            swap(arr[j + 1], arr[j]);
            j--;
        }
        while (!flag && j >= 0 && arr[j] < temp)
        {
            swap(arr[j + 1], arr[j]);
            j--;
        }
        arr[j + 1] = temp;
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
    insertionSort(arr, true);
    printVector(arr);
    insertionSort(arr, false);
    printVector(arr);
}