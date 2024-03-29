/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000

*/

#include <iostream>
using namespace std;
#include <vector>
vector<int> sortArrayByParity(vector<int> &A)
{
    int l = 0, r = A.size() - 1;
    while (l < r)
    {
        if (A[l] % 2 != 0)
        {
            swap(A[l], A[r]);
            --r;
        }
        else
        {
            ++l;
        }
    }
    return A;
}
int main()
{
}