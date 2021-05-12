/*
Tic-tac-toe is a game played between two players on a 3×3 grid. In a turn, a player chooses an empty cell and places their symbol on the cell. The players take alternating turns, where the player with the first turn uses the symbol X and the other player uses the symbol O. The game continues until there is a row, column, or diagonal containing three of the same symbol (X or O), and the player with that token is declared the winner. Otherwise if every cell of the grid contains a symbol and nobody won, then the game ends and it is considered a draw.

You are given a tic-tac-toe board A after a certain number of moves, consisting of symbols O, X, and underscore(_). Underscore signifies an empty cell.

Print

1: if the position is reachable, and the game has drawn or one of the players won.
2: if the position is reachable, and the game will continue for at least one more move.
3: if the position is not reachable.
Note:

Starting from an empty board, reachable position means that the grid is possible after a finite number of moves in the game where the players may or may not be playing optimally.
The answer for each testcase should be with respect to the present position and independent of the results in the further successive moves.
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains 3 lines of input where each line contains a string describing the state of the game in ith row.
Output
For each test case, output in a single line 1, 2 or 3 as described in the problem.

Constraints
1≤T≤39
Aij∈{X,O,_}
Subtasks
Subtask #1 (100 points): Original Constraints

Sample Input
3
XOX
XXO
O_O
XXX
OOO
___
XOX
OX_
XO_
Sample Output
2
3
1
Explanation
Test Case 1: The board is reachable, and although no player can win from this position, still the game continues.

Test Case 2: There can't be multiple winners in the game.

Test Case 3: The first player is clearly a winner with one of the diagonals.


*/

#include <bits/stdc++.h>
using namespace std;
int isWin(char ch, vector<string> tempStr)
{
    // for coloumn and row
    for (int i = 0; i < 3; i++)
    {
        if (tempStr[i][0] == ch && tempStr[i][0] == tempStr[i][1] && tempStr[i][1] == tempStr[i][2])
        {
            return 1;
        }
        if (tempStr[0][i] == ch && tempStr[0][i] == tempStr[1][i] && tempStr[1][i] == tempStr[2][i])
        {
            return 1;
        }
    }
    // for dig
    if (tempStr[0][0] == ch && tempStr[0][0] == tempStr[1][1] && tempStr[1][1] == tempStr[2][2])
        return 1;
    if (tempStr[0][2] == ch && tempStr[0][2] == tempStr[1][1] && tempStr[1][1] == tempStr[2][0])
        return 1;
    return 0;
}
int getRes(vector<string> &str)
{
    int x_count = 0, o_count = 0, __count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (str[i][j] == 'X')
            {
                x_count++;
            }
            else if (str[i][j] == 'O')
            {
                o_count++;
            }
        }
    }
    __count = 9 - x_count - o_count;
    if (x_count < o_count)
        return 3;
    if (x_count > o_count + 1)
        return 3;
    bool isXwins = isWin('X', str);
    bool isOwins = isWin('O', str);
    if (isXwins && isOwins)
    {
        return 3;
    }
    if (isXwins && x_count == o_count)
    {
        return 3;
    }
    if (isOwins && x_count > o_count)
    {
        return 3;
    }
    if (isXwins || isOwins)
    {
        return 1;
    }
    if (__count == 0)
    {
        return 1;
    }
    return 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        vector<string> str;
        for (int i = 0; i < 3; i++)
        {
            string t;
            cin >> t;
            str.push_back(t);
            // cout << t;
        }

        cout << getRes(str) << "\n";
    }
}