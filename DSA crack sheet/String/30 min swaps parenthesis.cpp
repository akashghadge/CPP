/*
You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

 

Example 1:

Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

 

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function minimumNumberOfSwaps() which takes the string S and return minimum number of operations required to balance the bracket sequence.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

 

Constraints:

1<=|S|<=100000


*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
int minimumNumberOfSwaps(string chars)
{
    // code here
    int countLeft = 0, countRight = 0;
    // swap stores the number of swaps
    // required imbalance maintains
    // the number of imbalance pair
    int swap = 0, imbalance = 0;

    for (int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == '[')
        {

            // Increment count of Left bracket
            countLeft++;

            if (imbalance > 0)
            {

                // swaps count is last swap count + total
                // number imbalanced brackets
                swap += imbalance;

                // imbalance decremented by 1 as it solved
                // only one imbalance of Left and Right
                imbalance--;
            }
        }
        else if (chars[i] == ']')
        {

            // Increment count of Right bracket
            countRight++;

            // imbalance is reset to current difference
            // between Left and Right brackets
            imbalance = (countRight - countLeft);
        }
    }
    return swap;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}