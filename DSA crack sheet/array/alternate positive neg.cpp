/*
Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with positive number.
 

Example 1:

Input: 
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output:
9 -2 4 -1 5 -5 0 -3 2
Example 2:

Input: 
N = 10
Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output:
5 -5 2 -2 4 -8 7 1 8 0 


Your Task:  
You don't need to read input or print anything. Your task is to complete the function rearrange() which takes the array of integers arr[] and n as parameters. You need to modify the array itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
 

Constraints:
1 ≤ N ≤ 107
-106 ≤ Arr[i] ≤ 107


*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
// here order is not important if important we can not do this solution in o(n) time
// so we firstly differentiate positive and negative first
// and then add one by one negative to each second place upto we found end
void rearrange(int arr[], int n)
{
    // code here
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }

    int i = 0, j = 0;
    int index = 0;
    while (i < pos.size() && j < neg.size())
    {
        if (index % 2 == 0)
        {
            arr[index] = pos[i];
            i++;
        }
        else
        {
            arr[index] = neg[j];
            j++;
        }
        index++;
    }
    while (i < pos.size())
    {
        arr[index] = pos[i];
        i++;
        index++;
    }
    while (j < neg.size())
    {
        arr[index] = neg[j];
        j++;
        index++;
    }
}
int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " Max is " << arr[i] << endl;
    }
}
int alternative(int *arr, int size)
{
    int end = size - 1;
    int i = 0;
    while (i < size)
    {
        if (end == i)
        {
            break;
        }
        if (arr[i] < 0)
        {
            swap(arr[i], arr[end]);
            end--;
            continue;
        }
        i++;
    }
    end++;
    printArray(arr, size);
    cout << "After sepration" << endl;

    for (int i = 1; i < size; i = i + 2)
    {
        if (arr[end] < 0)
        {
            swap(arr[end], arr[i]);
            end++;
        }
    }

    printArray(arr, size);
}

int main()
{
    int arr[] = {
        1,
        -1,
        -2, 2, -3, 3, 3, 3, -3, -3, -2, -2, -2, -4, -4, -4, -4};
    int size = sizeof(arr) / sizeof(arr[0]);
    alternative(arr, size);
}