/*
Game with nos 
Basic Accuracy: 80.49% Submissions: 5058 Points: 1
 You are given an array arr[], you have to re-construct an array arr[].
The values in arr[] are obtained by doing Xor of consecutive elements in the array.

Example 1:

â€‹Input : arr[ ] = {10, 11, 1, 2, 3}
Output : 1 10 3 1 3
Explanation:
At index 0, arr[0] xor arr[1] = 1
At index 1, arr[1] xor arr[2] = 10
At index 2, arr[2] xor arr[3] = 3
...
At index 4, No element is left So, it will remain as
it is.
New Array will be {1, 10, 3, 1, 3}.
*/

#include <iostream>
using namespace std;
int *game_with_number(int arr[], int n)
{

    // Complete the function
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] ^ arr[i + 1];

        if (i == n - 2)
        {
            break;
        }
    }
    return arr;
}
int main()
{
    
}