/*
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
Explanation :




 

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return 1 if it is correct, else it returns 0.

 

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= n, m <= 105
1 <= a[i], b[i] <= 2*105

*/

#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define vi vector<int>
#define vll vector<ll>
#define ll long long
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    vector<int> heap;
    int downHepify(int index)
    {
        int mini = index;
        int leftIndex = (2 * index) + 1;
        int rightIndex = (2 * index) + 2;
        if (leftIndex < heap.size() && heap[leftIndex] > heap[mini])
        {
            mini = leftIndex;
        }
        if (rightIndex < heap.size() && heap[rightIndex] > heap[mini])
        {
            mini = rightIndex;
        }
        if (index != mini)
        {
            swap(heap[index], heap[mini]);
            downHepify(mini);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        // your code here
        heap.insert(heap.end(), a.begin(), a.end());
        heap.insert(heap.end(), b.begin(), b.end());
        for (int i = (heap.size() / 2) - 1; i >= 0; i--)
        {
            downHepify(i);
        }
        return heap;
    }
};
int main()
{
    FAST;

    return 0;
}