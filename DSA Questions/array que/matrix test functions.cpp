#include <iostream>
using namespace std;
void cursorMove(char);
void display();
int check();
void swap(int *, int *);
int pos_row = 3;
int pos_col = 3;
int ans[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
int puzzel_array[4][4] = {
    12, 3, 5, 7,
    2, 10, 13, 1,
    4, 9, 8, 14,
    6, 11, 15, 0};
int main()
{
    cursorMove('u');
}

void cursorMove(char move)
{
    if (move == 'u' || move == 'U')
    {
        if (pos_col > 0)
        {
            swap(puzzel_array[pos_row][pos_col], puzzel_array[pos_row][pos_col + 1]);
            pos_col++;
        }
        else
        {
            cout << "WE ARE UNABLE TO MOVE THE CURSER" << endl;
        }
    }
    else if (move == 'd' || move == 'D')
    {
        if (pos_col < 3)
        {
            swap(puzzel_array[pos_row][pos_col], puzzel_array[pos_row][pos_col - 1]);
            pos_col--;
        }
        else
        {
            cout << "WE ARE UNABLE TO MOVE THE CURSER" << endl;
        }
    }
    else if (move == 'r' || move == 'R')
    {
        if (pos_row > 0)
        {
            swap(puzzel_array[pos_row][pos_col], puzzel_array[pos_row + 1][pos_col]);
            pos_row++;
        }
        else
        {
            cout << "WE ARE UNABLE TO MOVE THE CURSER" << endl;
        }
    }
    else if (move == 'l' || move == 'L')
    {
        if (pos_row < 0)
        {
            swap(puzzel_array[pos_row][pos_col], puzzel_array[pos_row - 1][pos_col]);
            pos_row--;
        }
        else
        {
            cout << "WE ARE UNABLE TO MOVE THE CURSER" << endl;
        }
    }
    else
    {
        cout << "WE ARE UNABLE TO MOVE THE CURSER" << endl;
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}