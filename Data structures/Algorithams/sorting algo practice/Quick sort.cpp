#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
/*
    for quick sort we are make partion on the basisi of pivot element 
    just like
    elements lesser than pivot | elements greater than pivot
    do this process again and again for smaller parts i.e devide and conq.
*/
void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int partition(vector<int> &arr, int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        cout << "hello" << endl;
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    return end;
}
int QuickSort(vector<int> &arr, int lb, int ub)
{
    if (ub > lb)
    {
        int mid = partition(arr, lb, ub);
        QuickSort(arr, lb, mid - 1);
        QuickSort(arr, mid + 1, ub);
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
    QuickSort(arr, 0, arr.size() - 1);
    printVector(arr);
}