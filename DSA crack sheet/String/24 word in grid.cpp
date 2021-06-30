/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
 

Example 1:

Input: grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: {{0,0}}
Expalnation: From (0,0) one can find "abc"
in horizontally right direction.
Example 2:

Input: grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
,word = "abe"
Output: {{0,0},{0,2},{1,0}}
Explanation: From (0,0) one can find "abe" in 
right-down diagonal. From (0,2) one can
find "abe" in left-down diagonal. From
(1,0) one can find "abe" in Horizontally right 
direction.
 

Your Task:
You don't need to read or print anyhting, Your task is to complete the function searchWord() which takes grid and word as input parameters and returns a list containg the positions from where the word originates in any direction. If there is no such position then returns an empty list.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions strating from the same coordinates, the list should contain the coordinates only once. 
 

Expected Time Complexity: O(n*m*k) where k is constant
Exected Space Complexity: O(1)
 

Constraints:
1 <= n <= m <= 100
1 <= |word| <= 10


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
vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
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
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}