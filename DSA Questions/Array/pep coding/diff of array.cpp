#include <iostream>
using namespace std;
int *diffofArray(int *arr1, int s1, int *arr2, int s2)
{
    int s3 = (s1 > s2 ? s1 : s2) + 1;
    int res[s3];
    int i = s1 - 1;
    int j = s2 - 1;
    int k = s3 - 1;
    int diff = 0;
    while (k >= 0)
    {
        if (arr1[i] >= arr2[j])
        {
            diff = arr1[i] - arr2[j];
        }
        else
        {
            diff = 10 + arr1[i] - arr2[j];
            arr1[i + 1]--;
        }

        res[k] = diff;
        i--;
        j--;
        k--;
    }
    for (int val : res)
    {
        cout << val;
    }
}
int main()
{
    int arr1[] = {1, 0, 0, 0};
    int arr2[] = {5, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    diffofArray(arr1, size1, arr2, size2);
}