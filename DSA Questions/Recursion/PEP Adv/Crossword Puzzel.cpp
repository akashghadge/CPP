/*
we have givent 2d array of 
- and + 
e.g
+ - +
+ - -
+ - +

here at minus we can fill word which have same size as -  in this case 3 and 2 and horizontal and vertical word can share charecters
 
for LE ALE

+ A +
+ L E
+ E +
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
void print(vector<vector<char>> arr)
{
    for (auto val : arr)
    {
        for (auto v : val)
        {
            cout << v;
        }
        cout << en;
    }
}

bool canWePlaceHorizontal(vector<vector<char>> &board, string word, int row, int col)
{
    // check before first and after last there is any white space or privious charecter
    if (col - 1 >= 0 && board[row][col - 1] != '+')
        return false;
    else if (col + word.size() < board.size() && board[row][col + word.size()] != '+')
        return false;

    for (int i = 0; i < word.size(); i++)
    {
        // out of the box ;)
        if (col + i >= board.size())
            return false;
        if (board[row][col + i] == '-' || board[row][col + i] == word[i])
            continue;
        else
            return false;
    }
    return true;
}
vector<bool> placeHorizontal(vector<vector<char>> &board, string word, int row, int col)
{
    vector<bool> changes(word.size(), false);
    for (int i = 0; i < word.size(); i++)
    {
        if (board[row][col + i] == '-')
        {
            board[row][col + i] = word[i];
            changes[i] = true;
        }
    }
    return changes;
}
void unPlaceHorizontal(vector<vector<char>> &board, vector<bool> placement, int row, int col)
{
    for (int i = 0; i < placement.size(); i++)
    {
        if (placement[i])
        {
            board[row][col + i] = '-';
        }
    }
}

bool canWePlaceVertical(vector<vector<char>> &board, string word, int row, int col)
{
    // check before first and after last there is any white space or privious charecter
    if (row - 1 >= 0 && board[row - 1][col] != '+')
        return false;
    else if (row + word.size() < board.size() && board[row + word.size()][col] != '+')
        return false;

    for (int i = 0; i < word.size(); i++)
    {
        // out of the box ;)
        if (row + i >= board.size())
            return false;
        if (board[row + i][col] == '-' || board[row + i][col] == word[i])
            continue;
        else
            return false;
    }
    return true;
}
vector<bool> placeVertical(vector<vector<char>> &board, string word, int row, int col)
{
    vector<bool> changes(word.size(), false);
    for (int i = 0; i < word.size(); i++)
    {
        if (board[row + i][col] == '-')
        {
            board[row + i][col] = word[i];
            changes[i] = true;
        }
    }
    return changes;
}
void unPlaceVertical(vector<vector<char>> &board, vector<bool> placement, int row, int col)
{
    for (int i = 0; i < placement.size(); i++)
    {
        if (placement[i])
        {
            board[row + i][col] = '-';
        }
    }
}

void helper(int curr, int total, vector<vector<char>> &board, vector<string> words)
{
    if (curr >= total)
    {
        print(board);
        return;
    }
    string word = words[curr];
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (canWePlaceHorizontal(board, word, i, j))
            {
                vector<bool> placement = placeHorizontal(board, word, i, j);
                helper(curr + 1, total, board, words);
                unPlaceHorizontal(board, placement, i, j);
            }

            if (canWePlaceVertical(board, word, i, j))
            {
                vector<bool> placement = placeVertical(board, word, i, j);
                helper(curr + 1, total, board, words);
                unPlaceVertical(board, placement, i, j);
            }
        }
    }
}
void sol(vector<vector<char>> board, vector<string> words)
{
    helper(0, words.size(), board, words);
}
int main()
{
    FAST;
    int n, m;
    n = 10;
    m = 10;
    // cin >> n >> m;
    vector<string> boardStr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> boardStr[i];
    }

    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = boardStr[i][j];
        }
    }
    int num;
    cin >> num;
    vector<string> words(num);
    for (int i = 0; i < num; i++)
    {
        cin >> words[i];
    }

    sol(board, words);
    return 0;
}