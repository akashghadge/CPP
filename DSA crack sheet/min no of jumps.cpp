#include <iostream>
using namespace std;
int minJumps(int *arr, int size);
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
        int size;
        cin >> size;
        int arr[size];
        setArray(arr, size);
        printArray(arr, size);
        int result = minJumps(arr, size);
        cout << result << endl;
    }
}

int minJumps(int *arr, int size)
{
    int i;
    int jumps = 0;
    int jumpLength = 0;
    for (i = 0; i < size;)
    {
        if (arr[i] == 0)
        {
            return NULL;
            break;
        }
        else if (i == size - 1)
        {
            return jumps;
            break;
        }

        else
        {
            jumpLength = arr[i];
            i += jumpLength;
            jumps++;
        }
    }
    return jumps;
}