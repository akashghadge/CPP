#include <bits/stdc++.h>
using namespace std;

/*
Explanation:
Here we can say that
basic principle:
we need to have all the smaller elements in first array and all the larger in second
so we iterate from first element of both arrays

if we found element which is smaller than ith element in first array
we can say that the last element of first array is now the larger than that element and we can swapped out it to the second array so we do
swap(b[j++],a[k--]) here we don't increase the ith iterator cause may be ith element is larger than all the possible ones
*/
void merge(int a[], int b[], int n, int m)
{
    // code here
    int i = 0, j = 0, k = n - 1;
    while (i <= k && j < m)
    {
        if (a[i] < b[j])
            i++;
        else
        {
            swap(b[j++], a[k--]);
        }
    }
    sort(a, a + n);
    sort(b, b + m);
}
void setArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}
void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size1;
        cin >> size1;
        int arr1[size1];
        int size2;
        cin >> size2;
        int arr2[size2];
        setArray(arr1, size1);
        setArray(arr2, size2);
        printArray(arr1, size1);
        printArray(arr2, size2);
        merge(arr1, arr2, size1, size2);
        cout << "Result" << endl;
        printArray(arr1, size1);
        printArray(arr2, size2);
    }
}
