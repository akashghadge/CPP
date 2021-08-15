/*
Implement a Queue using two stack s1 and s2.

Example 1:

Input:
enqueue(2)
enqueue(3)
dequeue()
enqueue(4)
dequeue()
Output: 2 3
Explanation:
enqueue(2) the queue will be {2}
enqueue(3) the queue will be {3 2}
dequeue() the poped element will be 2 
the stack will be {3}
enqueue(4) the stack will be {4 3}
dequeue() the poped element will be 3.  
Example 2:

Input:
enqueue(2)
dequeue()
enqueue(3)
dequeue()
Output: 2 -1
Your Task:

Since this is a function problem, you don't need to take inputs. You are required to complete the two methods enqueue() which takes an integer 'x' as input denoting the element to be pushed into the queue and dequeue() which returns the integer poped out from the queue.

Expected Time Complexity: O(1) for enqueue() and O(n) for dequeue()
Expected Auxiliary Space: O(1) for both enqueue() and dequeue()

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100


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
class Queue
{
    stack<int> input, output;

public: 
    void enqueue(int x)
    {
        input.push(x);
    }

    int dequeue()
    {
        if (input.empty())
            return -1;
        while (input.size() != 1)
        {
            output.push(input.top());
            input.pop();
        }
        int temp = input.top();
        input.pop();
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        return temp;
    }
};
int main()
{
    FAST;

    return 0;
}