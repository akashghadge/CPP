/*
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.


Example 1:

Input:
Stack: 18 19 29 15 16
Output: 15
Explanation:
The minimum element of the stack is 15.
 


Your Task:
Since this is a function problem, you don't need to take inputs. You just have to complete 5 functions, push() which takes the stack and an integer x as input and pushes it into the stack; pop() which takes the stack as input and pops out the topmost element from the stack; isEmpty() which takes the stack as input and returns true/false depending upon whether the stack is empty or not; isFull() which takes the stack and the size of the stack as input and returns true/false depending upon whether the stack is full or not (depending upon the
given size); getMin() which takes the stack as input and returns the minimum element of the stack. 
Note: The output of the code will be the value returned by getMin() function.


Expected Time Complexity: O(N) for getMin, O(1) for remaining all 4 functions.
Expected Auxiliary Space: O(1) for all the 5 functions.


Constraints:
1 ≤ N ≤ 104


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
void push(stack<int> &s, int a)
{
    // Your code goes here
    s.push(a);
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    return s.size() >= n ? true : false;
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    return s.empty();
}

int pop(stack<int> &s)
{
    // Your code goes here
    s.pop();
}

int getMin(stack<int> &s)
{
    // Your code goes here
    int len = s.size();
    int arr[s.size()];
    int i = 0;
    while (!s.empty())
    {
        arr[i] = s.top();
        s.pop();
        i++;
    }
    int m = 1e7;
    for (int i = 0; i < len; i++)
    {
        m = min(m, arr[i]);
    }
    return m;
}
int main()
{
    FAST;

    return 0;
}