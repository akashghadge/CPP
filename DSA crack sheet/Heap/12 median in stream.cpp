/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 
 

Example 2:

Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 
Your Task:
You are required to complete the class Solution. 
It should have 2 data members to represent 2 heaps. 
It should have the following member functions:
insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
getMedian() does not take any arguments. It should return the current median of the stream.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
 
Constraints:
1 <= N <= 106
1 <= x <= 106

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

priority_queue<int> leftPQ;
priority_queue<int, vector<int>, greater<int>> rightPQ;
//Function to insert heap.
void insertHeap(int &x)
{
    if (rightPQ.size() > 0 && rightPQ.top() < x)
    {
        rightPQ.push(x);
    }
    else
    {
        leftPQ.push(x);
    }
}

//Function to balance heaps.
void balanceHeaps()
{
    if (leftPQ.size() - rightPQ.size() == 2)
    {
        rightPQ.push(leftPQ.top());
        leftPQ.pop();
    }
    else if (rightPQ.size() - leftPQ.size() == 2)
    {
        leftPQ.push(rightPQ.top());
        rightPQ.pop();
    }
    else
    {
        return;
    }
}

//Function to return Median.
double getMedian()
{
    if (leftPQ.size() == 0 && rightPQ.size() == 0)
        return -1;
    else if (leftPQ.size() == rightPQ.size())
        return double(leftPQ.top() + rightPQ.top()) / 2;
    else if (leftPQ.size() > rightPQ.size())
        return leftPQ.top();
    else
        return rightPQ.top();
}

int main()
{
    FAST;
    int arr[] = {5, 10, 15};
    for (int i = 0; i < 3; i++)
    {
        int val = arr[i];
        insertHeap(val);
        balanceHeaps();
        cout << getMedian() << en;
    }

    return 0;
}