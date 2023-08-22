/*

1) K’th smallest element in an unsorted array using QuickSelect O(N^2) but O(N) on average
    Run quick sort algorithm on the input array
        In this algorithm pick a pivot element and move it to it’s correct position
        Now, if index of pivot is equal to K then return the value, else if the index of pivot is greater than K, then recur for the left subarray, else recur for the right subarray
        Repeat this process until the element at index K is not found
        https://www.cdn.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here
        sort(arr, arr + (r + 1));
        return arr[k - 1];
    }
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here
        priority_queue<int> pq;
        for (int i = 0; i <= r; i++) 
        {
            if (pq.size() == k and pq.top() > arr[i])
            {
                pq.pop(), pq.push(arr[i]);
            }
            else if (pq.size() < k)
            {
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};
int main()
{
}