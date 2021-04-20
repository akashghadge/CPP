#include <iostream>
using namespace std;
int *sumofArray(int *arr1, int s1, int *arr2, int s2)
{
    int s3 = (s1 > s2 ? s1 : s2) + 1;
    int res[s3];
    int i = s1 - 1;
    int j = s2 - 1;
    int k = s3 - 1;
    int carry = 0;
    int sum = 0;
    while (k >= 0)
    {
        if (i >= 0)
        {
            sum += arr1[i];
        }
        if (j >= 0)
        {
            sum += arr2[j];
        }
        sum += carry;
        res[k] = sum % 10;
        carry = sum / 10;
        sum = 0;
        i--;
        j--;
        k--;
    }
    if (carry != 0)
    {
        cout << carry;
    }
    for (int val : res)
    {
        cout << val;
    }
}
int main()
{
    int arr1[] = {1, 0, 0, 0};
    int arr2[] = {4, 5, 6, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    sumofArray(arr1, size1, arr2, size2);
}