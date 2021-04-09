#include <iostream>
using namespace std;
int winner(int num);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int pile;
        cout << "PLEASE ENTER THE NUMBER OF THE PILES :" << endl;
        cin >> pile;
        int result = winner(pile);
        if (result == 0)
        {
            cout << "PLAYER B IS WINNER" << endl;
        }
        else
        {
            cout << "PLAYER A IS WINNER" << endl;
        }
    }
}
int winner(int num)
{
    return num % 2;
}