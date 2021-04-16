#include <iostream>
using namespace std;

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
int bestTime(int *, int);
int usingKadensAlgo(int *, int);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr[size];
        setArray(arr, size);
        printArray(arr, size);
        int result = bestTime(arr, size);
        int res = usingKadensAlgo(arr, size);
        cout << result << endl;
        cout << res << endl;
    }
}

int bestTime(int *arr, int size)
{
    int min = arr[0];
    int profit = 0;
    int i;
    for (i = 0; i < size - 1; i++)
    {
        int j;
        for (j = i + 1; j < size; j++)
        {
            if (profit < arr[j] - arr[i])
            {
                profit = arr[j] - arr[i];
            }
        }
    }
    return profit;
}

int usingKadensAlgo(int *arr, int size)
{
    int profit = INT8_MIN;
    int currentProfit = 0;
    int currentStock = arr[0];
    for (int i = 0; i < size; i++)
    {
        currentProfit += (arr[i] - currentStock);
        currentStock = arr[i];
        if (currentProfit < 0)
        {
            currentProfit = 0;
        }
        if (currentProfit > profit)
        {
            profit = currentProfit;
        }
    }
    return profit;
}