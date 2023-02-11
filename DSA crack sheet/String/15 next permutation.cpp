/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the
given array is {1, 2, 4, 3, 5, 6}.
Example 2:

Input: N = 3
arr = {3, 2, 1}
Output: {1, 2, 3}
Explaination: As arr[] is the last
permutation. So, the next permutation
is the lowest one.
Your Task:
You do not need to read input or print anything. Your task is to complete the function nextPermutation() which takes N and arr[ ] as input parameters and returns a list of numbers containing the next permutation.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10000


*/
/*
1,3,2
dic orders are
1,2,3
1,3,2
2,1,2
2,3,1
3,1,2
3,2,1

brute force -> generate all possible combos
algo is below

Intuition in striver video->
as we know here
when any permutation is going with flow
it starts like
increasing flow and then if we go to next one
it  will lke just one greater element is shifted towards left
i.e
1,2,3 -> 1,3,2
so for next one wee need to to one thing where
this flow of increasing top decreasing occurs
use breakpoint and swap with it next just greater element in next part
i.e 1,4,5,3,2 -> here break point is 4 value
swap it with next greater one i.e 5 if(here 6 is there then also 5 is used to swap cause 5 is next greater not 6)
1,5,4,3,2 this greater permutation but not just next one
for just next one reverse the breakpoint+1 to end part
cause this is already sorted and no need to sort it just reverse it
*/
#include <bits/stdc++.h>
#define en "\n"
using namespace std;
class Solution
{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        // code here
        if (N <= 1)
        {
            return arr;
        }
        int k, l, i;
        for (i = N - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                k = i;
            }
            else
            {
                break;
            }
        }
        if (i < 0)
        {
            sort(arr.begin(), arr.end());
        }
        else
        {
            k = i;
            for (l = N - 1; l > k; l--)
            {
                if (arr[l] > arr[k])
                {
                    break;
                }
            }
            swap(arr[l], arr[k]);
            reverse(arr.begin() + k + 1, arr.end());
        }
        return arr;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}