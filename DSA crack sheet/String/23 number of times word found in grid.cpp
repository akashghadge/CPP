/*
Given a 2-Dimensional character array and a string, we need to find the given string in 2-dimensional character array such that individual characters can be present left to right, right to left, top to down or down to top.

Examples: 

Input : a ={
            {D,D,D,G,D,D},
            {B,B,D,E,B,S},
            {B,S,K,E,B,K},
            {D,D,D,D,D,E},
            {D,D,D,D,D,E},
            {D,D,D,D,D,G}
           }
        str= "GEEKS"
Output :2

Input : a = {
            {B,B,M,B,B,B},
            {C,B,A,B,B,B},
            {I,B,G,B,B,B},
            {G,B,I,B,B,B},
            {A,B,C,B,B,B},
            {M,C,I,G,A,M}
            }
        str= "MAGIC"

Output :4

*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool patterFound(vector<vector<char>> &grid, string &word, int posY, int posX)
{
    if (grid[posY][posX] != word[0])
        return false;

    int len = word.length();

    for (int dir = 0; dir < 8; dir++)
    {
        int k, rd = posY + x[dir], cd = posX + y[dir];

        for (k = 1; k < len; k++)
        {

            if (rd >= grid.size() || rd < 0 || cd >= grid[0].size() || cd < 0)
                break;

            // If not matched,  break
            if (grid[rd][cd] != word[k])
                break;

            // Moving in particular direction
            rd += x[dir], cd += y[dir];
        }

        // If all character matched, then value of k must
        // be equal to length of word
        if (k == len)
            return true;
    }
    return false;
}
int searchWord(vector<vector<char>> grid, string word)
{
    vector<vector<int>> ans;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (patterFound(grid, word, i, j))
            {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(
                    temp);
            }
        }
    }
    return ans.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}