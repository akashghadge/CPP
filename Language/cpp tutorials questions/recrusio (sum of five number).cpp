#include <iostream>
using namespace std;
int num1;
int sum;
int i = 1;
int main()
{
    if (i > 5)
    {
        cout << "THE ADDITION IS THE " << sum << endl;
        return 0;
    }
    else
    {
        cout << "PLESE ENETER THE NO FOR " << i << " POSITIONS" << endl;
        cin >> num1;
        sum = sum + num1;
        i++;
        main();
    }
}