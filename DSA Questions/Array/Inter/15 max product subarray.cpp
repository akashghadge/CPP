#include <iostream>
using namespace std;
int maxProduct(int *arr, int size)
{
    int maxProduct = arr[0];
    for (int i = 0; i < size; i++)
    {
        int current = arr[0];
        for (int j = i + 1; j < size; j++)
        {
            maxProduct = max(current, maxProduct);
            current *= arr[j];
        }
        maxProduct = max(current, maxProduct);
    }
    return maxProduct;
}
int maxProductOptimise(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
    }
}
int main()
{
    int arr[] = {6, -3, -10, 0, 2};
    cout << maxProduct(arr, 5);
}