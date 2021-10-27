/*
A board of length m and width n is given, we need to break this board into m*n squares such that cost of breaking is minimum. cutting cost for each edge will be given for the board. In short, we need to choose such a sequence of cutting such that cost is minimized. 
Examples: 
 



For above board optimal way to cut into square is:
Total minimum cost in above case is 42. It is 
evaluated using following steps.

Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces

Cost 4 Horizontal cut         Cost = 0 + 4*1 = 4
Cost 4 Vertical cut        Cost = 4 + 4*2 = 12
Cost 3 Vertical cut        Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut        Cost = 18 + 2*3 = 24
Cost 2 Vertical cut        Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut        Cost = 30 + 1*4 = 34
Cost 1 Vertical cut        Cost = 34 + 1*4 = 38
Cost 1 Vertical cut        Cost = 38 + 1*4 = 42


This problem can be solved using greedy approach, If total cost is denoted by S, then S = a1w1 + a2w2 … + akwk, where wi is a cost of certain edge cutting and ai is corresponding coefficient, The coefficient ai is determined by the total number of cuts we have competed using edge wi at the end of the cutting process. Notice that sum of the coefficients is always constant, hence we want to find a distribution of ai obtainable such that S is minimum. To do so we perform cuts on highest cost edge as early as possible, which will reach to optimal S. If we encounter several edges having the same cost, we can cut any one of them first. 
Below is the solution using above approach, first we sorted the edge cutting costs in reverse order, then we loop in them from higher-cost to lower-cost building our solution. Each time we choose an edge, counterpart count is incremented by 1, which is to be multiplied each time with corresponding edge cutting cost. 
Notice below used sort method, sending greater() as 3rd argument to sort method sorts number in non-increasing order, it is predefined function of the library. 

*/

// C++ program to divide a board into m*n squares
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/* SPOJ: CHOCOLA
Idea: Greedy Algorithm Stays Ahead
The number of breaks needed is always the same.
#Proof:
C(n,m) = n + m + n*m
C(0,0) = 0 (a single box choclate needs 0 cut)
Cut horizontally:
C(n,m) = 1 + C(a,m) + C(b,m) such that a+b+1 = n
C(n,m) = 1 + a+m+a*m + b+m+b*m
       = 1 + (n-1) + 2*m + (n-1)*m
       = n + m + n*m   :)
equally for vertical cut
#
Observation: the problem is similar to weight distribution problem
Observation: each cut will happen sooner or later
Observation: the "weight" of a cut is non decreasing
Observation: if a vertical and horizontal cost are equal, cutting 
order does not matter. Proof?
So we greedily choose the largest cut-cost each time
*/

int x[1003], y[1003];

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int m, n;
        cin >> m >> n;
        for (int i = 1; i < m; ++i)
        {
            cin >> x[i];
        }
        for (int i = 1; i < n; ++i)
        {
            cin >> y[i];
        }
        int h = 1, v = 1;
        sort(x + 1, x + m);
        reverse(x + 1, x + m);
        sort(y + 1, y + n);
        reverse(y + 1, y + n);
        int i = 1, j = 1;
        int ans = 0;
        while (i < m && j < n)
        {
            if (x[i] > y[j])
            {
                ans += x[i] * v;
                ++h;
                ++i;
            }
            else
            {
                ans += y[j] * h;
                ++v;
                ++j;
            }
        }
        if (i < m)
        {
            int sum = 0;
            while (i < m)
            {
                sum += x[i];
                ++i;
            }
            ans += sum * v;
        }
        else
        {
            int sum = 0;
            while (j < n)
            {
                sum += y[j];
                ++j;
            }
            ans += sum * h;
        }
        cout << ans << endl;
    }
    return 0;
}