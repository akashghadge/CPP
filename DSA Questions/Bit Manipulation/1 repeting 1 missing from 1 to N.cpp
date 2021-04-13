#include <iostream>
using namespace std;
#include <vector>
/*
    
*/
vector<int> missingDup(int *arr, int size)
{
    vector<int> ans;
    int sumDup = 0;
    int sumN = 0;
    for (int i = 0; i < size; i++)
    {
        sumDup ^= arr[i];
    }
    for (int i = 0; i <= size; i++)
    {
        sumN ^= i;
    }

    printf("hello\n");
    int XOR = sumN ^ sumDup;
    int rsb = XOR & (-XOR);
    int x = 0;
    int y = 0;
    for (int i = 0; i < size; i++)
    {
        if ((rsb & arr[i]) == 0)
        {
            x ^= arr[i];
        }
        else
        {
            y ^= arr[i];
        }
        x ^= i + 1;
        y ^= i + 1;
    }
    // for (int i = 0; i <= size; i++)
    // {
    // }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            cout << "Duplicate Number -> " << x << endl;
            cout << "Missing Number -> " << y << endl;
            break;
        }
        else if (arr[i] == y)
        {
            cout << "Duplicate Number -> " << y << endl;
            cout << "Missing Number -> " << x << endl;
            break;
        }
    }

    return ans;
}
int main()
{
    // int size;
    // cin >> size;
    // int arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> arr[i];
    // }
    // missingDup(arr, size);
    int arr[] = {1,
                 3,
                 4,
                 5,
                 6,
                 7,
                 7};
    missingDup(arr, 7);
}