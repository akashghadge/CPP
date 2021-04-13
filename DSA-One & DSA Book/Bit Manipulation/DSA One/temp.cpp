#include <iostream>
using namespace std;
#include "vector"
// in this problem basically we have array which have all k times repetative numbere except one number and we want to find it
//  arr[]={1,1,1,2,2,2,3} then 3 is that number

// solutioon
// here you have fixed gurantee that each number either occur k time or 1 time
// so make one array for 32 bits and count all occurance of bits for every position
// then get remainder through k times
int findKrepetative(int *arr, int size, int k)
{
    vector<int> bit(32, 0);

    int i = 0;
    while (i < size)
    {
        int j = 31;
        // printf("hello");
        while (arr[i] != 0)
        {
            bit[j] += (arr[i] % 2);
            arr[i] = arr[i] >> 1;
            j--;
        }
        i++;
    }
    int temp = 0;
    for (auto v : bit)
    {
        temp |= (v);
        temp = temp << 1;
    }

    cout << temp;
    return 0;
}
int main()
{
    int size;
    cin >> size;
    int arr[size];
    int k = 3;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    // int size = sizeof(arr) / sizeof(arr[0]);
    findKrepetative(arr, size, k);
}