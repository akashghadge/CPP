#include <iostream>
// #include <iomanip>
using namespace std;
void cusorMove(char);
void display();
int check();
void swap(int *, int *);
static int i_main;
static int j_main;
int ans[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
int puzzel_array[4][4] = {
    12, 3, 5, 7,
    2, 10, 13, 1,
    4, 9, 8, 14,
    6, 11, 15, 0};

int main()
{
    i_main = 3;
    j_main = 3;
    int terminate = 1;
    char cursor_move;
    display();
    while (terminate)
    {
        terminate = check();
        cout << "PLEASE ENTER THE MOVE :" << endl;
        cin >> cursor_move;
        cusorMove(cursor_move);
        display();
    }
}
int check()
{
    int i;
    int j;
    int count = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (puzzel_array[i][j] == ans[i][j])
            {
                count++;
            }
        }
    }
    if (count == 16)
    {
        // cout << "HI" << endl;
        return 0;
        // return 10;
    }
    else
    {
        // cout << "BYE" << endl;
        return 1;
    }
}
void display()
{
    int i;
    int j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << puzzel_array[i][j];
            cout << " ";
        }
        cout << "" << endl;
    }
}
void cusorMove(char move)
{
    if (move == 'l' || move == 'L')
    {
        if (j_main > 0)
        {
            swap(puzzel_array[i_main][j_main], puzzel_array[i_main][j_main - 1]);
            j_main--;
        }
        else
        {
            cout << "WE ARE UNABLE TO MOVE THE CURSER" << endl;
        }
    }
    else if (move == 'r' || move == 'R')
    {
        if (j_main < 3)
        {
            swap(puzzel_array[i_main][j_main], puzzel_array[i_main][j_main + 1]);
            j_main++;
        }
        else
        {
            cout << "WE ARE UNABLE TO MOVE THE CURSER" << endl;
        }
    }
    else if (move == 'd' || move == 'D')
    {
        if (i_main < 3)
        {
            swap(puzzel_array[i_main][j_main], puzzel_array[i_main + 1][j_main]);
            i_main++;
        }
        else
        {
            cout << "WE ARE UNABLE TO MOVE THE CURSER" << endl;
        }
    }
    else if (move == 'u' || move == 'U')
    {
        if (i_main > 0)
        {
            swap(puzzel_array[i_main][j_main], puzzel_array[i_main - 1][j_main]);
            i_main--;
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