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
// getmin have o(1) time and space also o(1)
int m = INT_MAX;
void push(stack<int> &s, int a)
{
    // Your code goes here
    if (s.size() == 0)
    {
        m = a;
        s.push(a);
    }
    else if (m > a)
    {
        // encryption if val m>a
        int val = (2 * a) - m;
        m = a;
        s.push(val);
    }
    else
    {
        s.push(a);
    }
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    return (s.size() >= n);
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    return s.empty();
}

int pop(stack<int> &s)
{
    // Your code goes here
    if (s.top() < m)
    {
        // decryption
        m = (2 * m) - s.top();
        s.pop();
    }
    else
    {
        s.pop();
    }
}

int getMin(stack<int> &s)
{
    return m;
}
int main()
{
    FAST;
    stack<int> st;
    push(st, 8);
    cout << m << en;
    push(st, 47);
    cout << m << en;
    push(st, 17);
    cout << m << en;
    push(st, 7);
    cout << m << en;
    push(st, 30);
    cout << m << en;
    push(st, 2);
    cout << m << en;
    pop(st);
    cout << m << en;
    pop(st);
    cout << m << en;
    pop(st);
    cout << m << en;
    pop(st);
    cout << m << en;
    pop(st);
    cout << m << en;
    pop(st);
    cout << m << en;
    return 0;
}