#include <iostream>
using namespace std;
long int prevstate = 1;
long int current = 0;
long int nextstate = 0;
long int end_state;
int i = 0;
int main()
{
    if (i == 0)
    {
        cout << "PLEASE ENTER UPTO WHICH TERM WOULD YOU LIKE TO PRINT THE FAB SERIES....:" << endl;
        cin >> end_state;
        i = 1;
    }
    if (i > end_state)
    {
        return 0;
    }
    else
    {
        nextstate = current + prevstate;
        prevstate = current;
        current = nextstate;
        cout << current << endl;
        i++;
        main();
    }
}