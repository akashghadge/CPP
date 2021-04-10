/*
Given N people standing in a circle where 1st is having a sword, find the luckiest person in the circle, if, from 1st soldier who is having a sword each has to kill the next soldier and handover the sword to next soldier, in turn, the soldier will kill the adjacent soldier and handover the sword to next soldier such that one soldier remains in this war who is not killed by anyone.
 

Example 1:

Input:
N = 5
Output:
3
Explanation:
In first go 1 3 5 (remains) 
as 2 and 4 killed by 1 and 3. 
In second go 3 will remain 
as 5 killed 1 and 3rd killed 5 
hence, 3 remains alive.
Example 2:

Input:
N = 10
Output:
5
Explanation:
In first 1 3 5 7 9 
remains as 2 4 6 8 10 
were killed by 1 3 5 7 
and 9. In second 1 5 9 
are left as 1 kills 3 
and  5 kill the 7th 
soldier.In third 5th 
soldiers remain alive as 
9 kills the 1st soldier and 
5 kill the 9th soldier.

Your Task:
You don't need to read input or print anything. Your task is to complete the function find() which takes an integer N as input parameter and returns the output as the soldier who was lucky in the game.
 

Expected Time Complexity: O(log N)
Expected Space Complexity: O(1)
*/

/*
here approch is 
here you can see 
first iteration only all even number will delete
and after first iteration last digit that is N number decidees which one survies
now it is iteration statrts
so
if zeroth bit of N is 0 then all numbers having 1st bit is 0 survive otherewise dies and it is also implicable of 1 vice versa
as it continues
0bit -> 1st bit 
1st bit -> 2nd bit
....
*/

#include <iostream>
using namespace std;
int hPowerOf2(int n)
{
    int h = 1;
    while (n > h)
    {
        h = h << 1;
    }
    return h >> 1;
}
int find(int N)
{
    // code here
    int p = hPowerOf2(N);
    int rem = N - p;
    return (2 * rem) + 1;
}
int main()
{
}