/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]
 

Constraints:

1 <= n <= 1000

*/

#include <iostream>
using namespace std;
#include <vector>
vector<int> sumZero(int n)
{
    vector<int> ans(n);
    int mid = n >> 1;
    int start = 0;
    int end = n - 1;
    int i = 1;
    while (start < mid)
    {
        ans[start] = i;
        ans[end] = (i * (-1));
        start++;
        end--;
        i++;
    }
    return ans;
}
int main()
{
}