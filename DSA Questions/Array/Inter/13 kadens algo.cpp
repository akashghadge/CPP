#include <iostream>
using namespace std;
// here basiclly kadens algorithm state the if sum goes to lesser then zero just discard that sum and start again new i.e sum=0 and if you find max sum then update maxSum
int maxSum(int *arr, int size)
{
    int maxSum = -1000000;
    int currentSum = 0;
    for (int i = 0; i < size; i++)
    {
        currentSum += arr[i];
        if (maxSum < currentSum)
        {
            maxSum = currentSum;
        }
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}
int main()
{
}